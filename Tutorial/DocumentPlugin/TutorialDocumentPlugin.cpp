#include "TutorialDocumentPlugin.hpp"

#include <wobjectimpl.h>

W_OBJECT_IMPL(Tutorial::DocumentPlugin)
namespace Tutorial
{

DocumentPlugin::DocumentPlugin(
    const score::DocumentContext& ctx,
    Id<score::DocumentPlugin> id,
    QObject* parent)
    : score::SerializableDocumentPlugin{ctx,
                                        std::move(id),
                                        "DocumentPlugin",
                                        parent}
{
}

}

template <>
void DataStreamReader::read(const Tutorial::DocumentPlugin& dev)
{
  insertDelimiter();
}

template <>
void DataStreamWriter::write(Tutorial::DocumentPlugin& plug)
{
  checkDelimiter();
}

template <>
void JSONObjectReader::read(const Tutorial::DocumentPlugin& plug)
{
}

template <>
void JSONObjectWriter::write(Tutorial::DocumentPlugin& plug)
{
}
