#pragma once
#include <iscore/tools/IdentifiedObject.hpp>

namespace Tutorial
{
class SimpleElement final : public IdentifiedObject<SimpleElement>
{
        Q_OBJECT

    public:
        SimpleElement(const Id<SimpleElement>& id, QObject* parent);

        template<typename Impl>
        SimpleElement(Deserializer<Impl>& vis, QObject* parent) :
            IdentifiedObject{vis, parent}
        {
            vis.writeTo(*this);
        }

        ~SimpleElement();
};
}
