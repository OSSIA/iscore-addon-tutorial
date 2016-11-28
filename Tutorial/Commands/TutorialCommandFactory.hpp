#pragma once
#include <iscore/command/SerializableCommand.hpp>

namespace Tutorial
{
inline const CommandParentFactoryKey& CommandFactoryName()
{
    static const CommandParentFactoryKey key{"Tutorial"};
    return key;
}
}
