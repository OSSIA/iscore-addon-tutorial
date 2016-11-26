#include "TutorialProcessModel.hpp"

namespace Tutorial
{

ProcessModel::ProcessModel(
        const TimeValue& duration,
        const Id<Process::ProcessModel>& id,
        QObject* parent):
    Process::ProcessModel{duration, id, "TutorialProcess", parent}
{

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
    insertDelimiter();
}

template<>
void Visitor<Writer<DataStream>>::writeTo(
        Tutorial::ProcessModel& Tutorial)
{
    checkDelimiter();
}

template<>
void Visitor<Reader<JSONObject>>::readFrom_impl(
        const Tutorial::ProcessModel& Tutorial)
{
}

template<>
void Visitor<Writer<JSONObject>>::writeTo(
        Tutorial::ProcessModel& Tutorial)
{
}
