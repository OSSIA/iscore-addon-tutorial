#pragma once
#include <score/plugins/panel/PanelDelegate.hpp>
#include <score/plugins/panel/PanelDelegateFactory.hpp>

namespace Tutorial
{
/**
 * @brief A default side-panel implementation that will just display a text.
 */
class PanelDelegate final : public QObject, public score::PanelDelegate
{
public:
  PanelDelegate(const score::GUIApplicationContext& ctx);

private:
  QWidget* widget() override;

  const score::PanelStatus& defaultPanelStatus() const override;

  void on_modelChanged(score::MaybeDocument oldm, score::MaybeDocument newm)
      override;

  void setNewSelection(const Selection& s) override;

  QWidget* m_widget{};
};

class PanelDelegateFactory final : public score::PanelDelegateFactory
{
  SCORE_CONCRETE("11114a3b-f123-42f6-84d0-b3af124d5689")

  std::unique_ptr<score::PanelDelegate>
  make(const score::GUIApplicationContext& ctx) override;
};


}
