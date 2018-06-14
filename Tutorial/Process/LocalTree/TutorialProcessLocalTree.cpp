#include "TutorialProcessLocalTree.hpp"
#include <Tutorial/Process/TutorialProcessModel.hpp>
#include <Engine/LocalTree/Property.hpp>

namespace Tutorial
{

LocalTreeProcessComponent::LocalTreeProcessComponent(
        const Id<score::Component>& id,
        ossia::net::node_base& parent,
        Tutorial::ProcessModel& proc,
        Engine::LocalTree::DocumentPlugin& sys,
        QObject* parent_obj):
    Engine::LocalTree::ProcessComponent_T<Tutorial::ProcessModel>{parent, proc, sys, id, "TutorialComponent", parent_obj}
{
  add<ProcessModel::p_bananas>(proc);
}

LocalTreeProcessComponent::~LocalTreeProcessComponent()
{

}

}
