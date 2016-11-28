#include "TutorialProcessModel.hpp"

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

template<>
void Visitor<Reader<DataStream>>::readFrom_impl(
        const Tutorial::ProcessModel& Tutorial)
{
    m_stream << Tutorial.m_bananas;
    insertDelimiter();
}

template<>
void Visitor<Writer<DataStream>>::writeTo(
        Tutorial::ProcessModel& Tutorial)
{
    m_stream >> Tutorial.m_bananas;
    checkDelimiter();
}

template<>
void Visitor<Reader<JSONObject>>::readFrom_impl(
        const Tutorial::ProcessModel& Tutorial)
{
    m_obj["Bananas"] = Tutorial.m_bananas;
}

template<>
void Visitor<Writer<JSONObject>>::writeTo(
        Tutorial::ProcessModel& Tutorial)
{
    Tutorial.m_bananas = m_obj["Bananas"].toInt();
}
