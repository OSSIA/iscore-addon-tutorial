#pragma once
#include <iscore/plugins/application/GUIApplicationContextPlugin.hpp>

namespace Tutorial
{
class ApplicationPlugin final :
        public iscore::GUIApplicationContextPlugin
{
    public:
        ApplicationPlugin(
                const iscore::GUIApplicationContext& app);

    protected:
        void on_newDocument(iscore::Document& doc) override;
        void on_documentChanged(
                iscore::Document* olddoc,
                iscore::Document* newdoc) override;

        void initialize() override;

        iscore::GUIElements makeGUIElements() override;

        bool handleStartup() override;

        void on_initDocument(iscore::Document& doc) override;

        void on_loadedDocument(iscore::Document& doc) override;

        void on_createdDocument(iscore::Document& doc) override;

        void prepareNewDocument() override;

        void on_activeWindowChanged() override;
};
}
