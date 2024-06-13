#include "interface.h"
#include <memory>
#include <utility>
Ihm::Ihm(sf::RenderWindow *fenêtre) : abonnements(NB_SUJETS) {
    this->fenêtre = fenêtre;
    ImGui::SFML::Init(*fenêtre);
    abonnements[BOOL_TOR] = std::make_unique<int>();
}
void Ihm::affichage_ihm() {
    auto dt = this->horloge.restart();
    ImGui::SFML::Update(*this->fenêtre, dt);
    this->contenu();
    ImGui::SFML::Render(*this->fenêtre);
}
void Ihm::évènements_ihm(sf::Event évènements) {
    ImGui::SFML::ProcessEvent(évènements);
}
void Ihm::contenu() {
    // ImGui::ShowDemoWindow();
    ImGui::Begin("8====> 0:");
    // static bool check = true;
    ImGui::Checkbox("monde toroïdal", reinterpret_cast<bool *>(
                                          this->abonnements[BOOL_TOR].get()));
    ImGui::End();
}

void *Ihm::abonnement(enum sujets sujet) {
    return this->abonnements[sujet].get();
}
