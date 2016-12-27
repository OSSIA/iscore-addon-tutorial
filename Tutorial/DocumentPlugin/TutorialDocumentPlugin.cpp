#include "TutorialDocumentPlugin.hpp"

namespace Tutorial
{

DocumentPlugin::DocumentPlugin(
        const iscore::DocumentContext& ctx,
        Id<iscore::DocumentPlugin> id,
        QObject* parent):
    iscore::SerializableDocumentPlugin{ctx, std::move(id), "DocumentPlugin", parent}
{
}

}

template <>
void DataStreamReader::read(
        const Tutorial::DocumentPlugin& dev)
{
    insertDelimiter();
}

template <>
void DataStreamWriter::writeTo(
        Tutorial::DocumentPlugin& plug)
{
    checkDelimiter();
}

template <>
void JSONObjectReader::read(
        const Tutorial::DocumentPlugin& plug)
{

}

template <>
void JSONObjectWriter::writeTo(
        Tutorial::DocumentPlugin& plug)
{
}
