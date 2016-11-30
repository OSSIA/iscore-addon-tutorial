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

template<>
void Visitor<Reader<DataStream>>::readFrom_impl(
        const Tutorial::DocumentPlugin& dev)
{
    insertDelimiter();
}

template<>
void Visitor<Writer<DataStream>>::writeTo(
        Tutorial::DocumentPlugin& plug)
{
    checkDelimiter();
}

template<>
void Visitor<Reader<JSONObject>>::readFrom_impl(
        const Tutorial::DocumentPlugin& plug)
{

}


template<>
void Visitor<Writer<JSONObject>>::writeTo(
        Tutorial::DocumentPlugin& plug)
{
}
