#include "TutorialProcessLocalTree.hpp"

#include <LocalTree/Property.hpp>
#include <Tutorial/Process/TutorialProcessModel.hpp>

namespace Tutorial
{

LocalTreeProcessComponent::LocalTreeProcessComponent(
    const Id<score::Component>& id,
    ossia::net::node_base& parent,
    Tutorial::ProcessModel& proc,
    const score::DocumentContext& sys,
    QObject* parent_obj)
    : LocalTree::ProcessComponent_T<Tutorial::ProcessModel>{
          parent,
          proc,
          sys,
          id,
          "TutorialComponent",
          parent_obj}
{
  add<ProcessModel::p_bananas>(proc);
}

LocalTreeProcessComponent::~LocalTreeProcessComponent() {}

}
