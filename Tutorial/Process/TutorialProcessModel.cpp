#include "TutorialProcessModel.hpp"
#include <Tutorial/PolymorphicElement/PolymorphicElementFactory.hpp>

namespace Tutorial
{

ProcessModel::ProcessModel(
        const TimeValue& duration,
        const Id<Process::ProcessModel>& id,
        QObject* parent):
    Process::ProcessModel{duration, id, "TutorialProcess", parent}
{
    metadata().setInstanceName(*this);
}

int ProcessModel::bananas() const
{
    return m_bananas;
}

void ProcessModel::setBananas(int bananas)
{
    if (m_bananas == bananas)
        return;

    m_bananas = bananas;
    emit bananasChanged(bananas);
}

ProcessModel::ProcessModel(
        const ProcessModel& source,
        const Id<Process::ProcessModel>& id,
        QObject* parent):
    Process::ProcessModel{source, id, "TutorialProcess", parent}
{

}

QString ProcessModel::prettyName() const
{
    return tr("Tutorial Process");
}

void ProcessModel::startExecution()
{
}

void ProcessModel::stopExecution()
{
}

void ProcessModel::reset()
{
}

ProcessStateDataInterface* ProcessModel::startStateData() const
{
    return nullptr;
}

ProcessStateDataInterface* ProcessModel::endStateData() const
{
    return nullptr;
}

Selection ProcessModel::selectableChildren() const
{
    return {};
}

Selection ProcessModel::selectedChildren() const
{
    return {};
}

void ProcessModel::setSelection(const Selection& s) const
{
}

void ProcessModel::setDurationAndScale(const TimeValue& newDuration)
{
}

void ProcessModel::setDurationAndGrow(const TimeValue& newDuration)
{
}

void ProcessModel::setDurationAndShrink(const TimeValue& newDuration)
{
}

}

/**
 * Here lies the serialization code for the ProcessModel.
 * There is :
 * - a read method (read the program memory into a save file)
 * - a write method (write the save file to program memory).
 *
 * These methods must be implemented for two save formats :
 * - QDataStream : lean and fast (binary), but the order in which
 *   the data is saved must be the same than when reloading and
 *   there cannot be "missing" data.
 *
 * - JSON : slower, but human-readable, and keys can be missing.
 */
template<>
void Visitor<Reader<DataStream>>::readFrom_impl(
        const Tutorial::ProcessModel& proc)
{
    /** Save the SimpleElements **/
    m_stream << (int32_t) proc.simpleElements.size();
    for(const auto& e : proc.simpleElements)
    {
        readFrom(e);
    }

    /** Save the PolymorphicElements **/
    m_stream << (int32_t) proc.polymorphicElements.size();
    for(const auto& e : proc.polymorphicElements)
    {
        readFrom(e);
    }

    // Save a simple data member
    m_stream << proc.m_bananas;

    // Add an element in the stream that will be checked on loading.
    // This is not necessary, but very useful for debugging.
    insertDelimiter();
}

template<>
void Visitor<Writer<DataStream>>::writeTo(
        Tutorial::ProcessModel& proc)
{
    int32_t simple_count;
    m_stream >> simple_count;

    /** Load the SimpleElements
     * We can just instantiate them like this since there is
     * no inheritance / subclass
     */
    for(; simple_count -- > 0;)
    {
        proc.simpleElements.add(new Tutorial::SimpleElement{*this, &proc});
    }

    /** Load the PolymorphicElements
     * This is a bit more involved :
     * since we do not know the actual type of the PolymorphicElement,
     * we have to instantiate it from a factory.
     */
    int32_t poly_count;
    m_stream >> poly_count;

    auto& pl = components.interfaces<Tutorial::PolymorphicElementFactoryList>();
    for(; poly_count -- > 0;)
    {
        auto e = deserialize_interface(pl, *this, &proc);
        if(e)
        {
            proc.polymorphicElements.add(e);
        }
        else
        {
            // The save cannot be reloaded correctly, here we throw
            // but other options should be possible.
            throw std::runtime_error("Unable to load.");
        }
    }

    // Load a simple data member
    m_stream >> proc.m_bananas;

    // Check that the stream has not been corrupted.
    checkDelimiter();
}

/**
 * We now do the same thing, but in JSON.
 * Some things are shorter to write, others are sometimes longer.
 */
template<>
void Visitor<Reader<JSONObject>>::readFrom_impl(
        const Tutorial::ProcessModel& proc)
{
    m_obj["SimpleElements"] = toJsonArray(proc.simpleElements);
    m_obj["PolyElements"] = toJsonArray(proc.polymorphicElements);
    m_obj["Bananas"] = proc.m_bananas;
}

template<>
void Visitor<Writer<JSONObject>>::writeTo(
        Tutorial::ProcessModel& proc)
{
    for(const auto& json_vref : m_obj["SimpleElements"].toArray())
    {
        Deserializer<JSONObject> deserializer {json_vref.toObject()};
        proc.simpleElements.add(new Tutorial::SimpleElement{deserializer, &proc});
    }

    auto& pl = components.interfaces<Tutorial::PolymorphicElementFactoryList>();
    for(const auto& json_vref : m_obj["PolyElements"].toArray())
    {
        Deserializer<JSONObject> deserializer{json_vref.toObject()};
        auto e = deserialize_interface(pl, deserializer, &proc);
        if(e)
        {
            proc.polymorphicElements.add(e);
        }
        else
        {
            // The save cannot be reloaded correctly, here we throw
            // but other options should be possible.
            throw std::runtime_error("Unable to load.");
        }
    }

    proc.m_bananas = m_obj["Bananas"].toInt();
}
