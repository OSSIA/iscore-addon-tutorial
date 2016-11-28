#pragma once
#include <iscore/plugins/qt_interfaces/PluginRequirements_QtInterface.hpp>
#include <iscore/plugins/qt_interfaces/FactoryInterface_QtInterface.hpp>
#include <iscore/plugins/qt_interfaces/FactoryFamily_QtInterface.hpp>
#include <iscore/plugins/qt_interfaces/GUIApplicationContextPlugin_QtInterface.hpp>
#include <iscore/plugins/qt_interfaces/CommandFactory_QtInterface.hpp>

#include <iscore/application/ApplicationContext.hpp>
#include <iscore/command/CommandGeneratorMap.hpp>
#include <iscore/command/SerializableCommand.hpp>
#include <iscore/plugins/customfactory/FactoryFamily.hpp>

#include <QObject>
#include <utility>
#include <vector>

/**
 * @brief The iscore_addon_tutorial class
 *
 * This class is the entry-point of the i-score plugin.
 *
 * \ref iscore::PluginLoader::loadPlugins contains the plug-in loading code.
 * \ref iscore::ApplicationInterface::loadPluginData contains plug-in setup code.
 *
 * The loaded plug-in data can always be accessed through \ref iscore::AppContext
 * but it is better practice to have the objects depend on their requirements
 * through constructor injection, and provide these requirements in the object
 * factories which have access to the same context without requiring a singleton function.
 *
 * When making a plug-in, not all the interfaces used here may be necessary; this
 * one aims to give an overview of all the possibilities.
 */
class iscore_addon_tutorial final :
        public QObject,
        public iscore::Plugin_QtInterface,
        public iscore::FactoryInterface_QtInterface,
        public iscore::FactoryList_QtInterface,
        public iscore::GUIApplicationContextPlugin_QtInterface,
        public iscore::CommandFactory_QtInterface
{
        Q_OBJECT
        Q_PLUGIN_METADATA(IID FactoryInterface_QtInterface_iid)
        Q_INTERFACES(
                iscore::Plugin_QtInterface
                iscore::FactoryInterface_QtInterface
                iscore::FactoryList_QtInterface
                iscore::GUIApplicationContextPlugin_QtInterface
                iscore::CommandFactory_QtInterface
                )

    public:
        iscore_addon_tutorial();
        virtual ~iscore_addon_tutorial();

    private:
        // Defined in Plugin_QtInterface
        UuidKey<iscore::Plugin> key() const override;
        iscore::Version version() const override;

        QStringList required() const override;
        QStringList offered() const override;

        void updateSaveFile(
                QJsonObject& obj,
                iscore::Version obj_version,
                iscore::Version current_version) override;

        // Defined in FactoryList_QtInterface
        std::vector<std::unique_ptr<iscore::FactoryListInterface>> factoryFamilies() override;

        // Defined in FactoryInterface_QtInterface
        std::vector<std::unique_ptr<iscore::FactoryInterfaceBase>> factories(
                const iscore::ApplicationContext& ctx,
                const iscore::AbstractFactoryKey& key) const override;

        // Defined in GUIApplicationContextPlugin_QtInterface
        iscore::GUIApplicationContextPlugin* make_applicationPlugin(
                const iscore::GUIApplicationContext& app) override;

        // Defined in CommandFactory_QtInterface
        std::pair<const CommandParentFactoryKey, CommandGeneratorMap> make_commands() override;

};
