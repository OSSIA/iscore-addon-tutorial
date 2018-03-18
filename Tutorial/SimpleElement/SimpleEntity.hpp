#pragma once
#include <score/model/Entity.hpp>

namespace Tutorial
{
class SimpleEntity final :
        public score::Entity<SimpleEntity>
{
        Q_OBJECT

    public:
        SimpleEntity(const Id<SimpleEntity>& id, QObject* parent);

        ~SimpleEntity();
};
}
