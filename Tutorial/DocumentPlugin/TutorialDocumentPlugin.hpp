#pragma once
#include <iscore/plugins/documentdelegate/plugin/DocumentDelegatePluginModel.hpp>

namespace Tutorial
{
class DocumentPlugin;
}

UUID_METADATA(,
    iscore::DocumentPluginFactory,
    Tutorial::DocumentPlugin,
    "164843db-345f-4e31-b614-f8de5ca7e94f")

namespace Tutorial
{
class DocumentPlugin final :
        public iscore::SerializableDocumentPlugin
{
        Q_OBJECT
        ISCORE_SERIALIZE_FRIENDS(DocumentPlugin, DataStream)
        ISCORE_SERIALIZE_FRIENDS(DocumentPlugin, JSONObject)

        SERIALIZABLE_MODEL_METADATA_IMPL(DocumentPlugin)

        public:
            explicit DocumentPlugin(
                    const iscore::DocumentContext& ctx,
                    Id<iscore::DocumentPlugin> id,
                    QObject* parent);

        template<typename Impl>
        DocumentPlugin(
                const iscore::DocumentContext& ctx,
                Deserializer<Impl>& vis,
                QObject* parent):
            iscore::SerializableDocumentPlugin{ctx, vis, parent}
        {
            vis.writeTo(*this);
        }
};

using DocumentPluginFactory = iscore::DocumentPluginFactory_T<DocumentPlugin>;
}
