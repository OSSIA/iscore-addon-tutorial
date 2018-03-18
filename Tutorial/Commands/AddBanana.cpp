#include "AddBanana.hpp"
#include <score/model/path/PathSerialization.hpp>

namespace Tutorial
{
AddBanana::AddBanana(
        const Tutorial::ProcessModel& model):
    m_model{model}
{
}

void AddBanana::undo(const score::DocumentContext& ctx) const
{
    Tutorial::ProcessModel& proc = m_model.find(ctx);
    proc.setBananas(proc.bananas() - 1);
}

void AddBanana::redo(const score::DocumentContext& ctx) const
{
    Tutorial::ProcessModel& proc = m_model.find(ctx);
    proc.setBananas(proc.bananas() + 1);
}

void AddBanana::serializeImpl(DataStreamInput& s) const
{
    s << m_model;
}

void AddBanana::deserializeImpl(DataStreamOutput& s)
{
    s >> m_model;
}
}
