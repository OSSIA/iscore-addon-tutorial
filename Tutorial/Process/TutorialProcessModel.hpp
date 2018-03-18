#pragma once
#include <Process/Process.hpp>
#include <Tutorial/Process/TutorialProcessMetadata.hpp>

#include <Tutorial/SimpleElement/SimpleElement.hpp>
#include <Tutorial/PolymorphicEntity/PolymorphicEntity.hpp>

#include <score/model/EntityMap.hpp>

namespace Tutorial
{
class ProcessModel final : public Process::ProcessModel
{
        SCORE_SERIALIZE_FRIENDS
        PROCESS_METADATA_IMPL(Tutorial::ProcessModel)

        Q_PROPERTY(int bananas READ bananas WRITE setBananas NOTIFY bananasChanged)

        Q_OBJECT

    public:
        ProcessModel(const TimeVal& duration,
                     const Id<Process::ProcessModel>& id,
                     QObject* parent);

        template<typename Impl>
        ProcessModel(Impl& vis, QObject* parent) :
            Process::ProcessModel{vis, parent}
        {
            vis.writeTo(*this);
        }

        score::EntityMap<SimpleElement> simpleElements;
        score::EntityMap<PolymorphicEntity> polymorphicEntities;

        int bananas() const;
        void setBananas(int bananas);

    Q_SIGNALS:
        void bananasChanged(int bananas);

    private:
        QString prettyName() const override;
        void startExecution() override;
        void stopExecution() override;
        void reset() override;
        ProcessStateDataInterface*startStateData() const override;
        ProcessStateDataInterface*endStateData() const override;
        Selection selectableChildren() const override;
        Selection selectedChildren() const override;
        void setSelection(const Selection& s) const override;

        void setDurationAndScale(const TimeVal& newDuration) override;
        void setDurationAndGrow(const TimeVal& newDuration) override;
        void setDurationAndShrink(const TimeVal& newDuration) override;

        int m_bananas{};
};
}
