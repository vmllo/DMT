#include "GUI.hpp"
#include "Config.hpp"
#include <cmath>
#include <string.h>
#include "stats.hpp"

int main()
{
    GUI textbox[11];
    GUI playerBox[11];
    GUI choiceBox[11];
    GUI button[11];
    GUI displayBox[7];
    GUI displaybuttons[7];
    GUI displayPlayerBox[2];
    Config con;
    sf::RectangleShape background;
    background.setFillColor(sf::Color::Black);
    int pos[8] = {250, 550, 650, 300, 250, 600, 300, 300};
    int posLetters[7] = {50, 450, 515, 180, 150, 515, 200};
    int posy[8] = {60, 60, 200, 200, 300, 300, 400, 600};
    int size[8] = {50, 200, 200, 200, 200, 200, 500, 500};
    int posDisplay[7] = {150, 250, 350, 450, 550, 650, 750};
    background.setSize(sf::Vector2f(1000, 1000));
    sf::RenderWindow characterCreationWindow(sf::VideoMode(1000, 1000), "Create them you nerd >:o");
    std::string playerInput;
    long long unicodeStuff;
    int spot = 0;
    int spotDisplay = 0;
    int posPos = 0;
    int temp = 0;
    int posyy = 3;
    sf::Vector2i p;
    sf::Vector2i p2;
    int i;
    int h;
    int flag = 0;
    int mouseFlag = 0;
    sf::String newName;
    unsigned int n;
    const char *stuff2;
    int arraySize2 = 5;
    Creature m[arraySize2];
    unsigned int state = Config::GUIstate::createState;
    choiceBox[0].textBox("ArialCE.ttf", "Create", 24, sf::Color::Red, 300, 700);
    choiceBox[1].textBox("ArialCE.ttf", "Done", 24, sf::Color::Red, 400, 700);
    button[9].setButton(75, 50, 300, 700, sf::Color::White);
    button[10].setButton(50, 50, 400, 700, sf::Color::White);

    for (int i = 0; i <= 6; i++)
    {
        playerBox[i].textBox("ArialCE.ttf", con.target[i], 24, sf::Color::Red, posLetters[i], posy[i]);
    }

    for (int i = 0; i <= 8; i++)
    {
        button[i].setButton(size[i], 50, pos[i], posy[i], sf::Color::White);
    }

    while (characterCreationWindow.isOpen())
    {
        sf::Event event;
        while (characterCreationWindow.pollEvent(event))
        {
            if (!mouseFlag)
            {
                if (event.type == sf::Event::MouseButtonPressed)
                {
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        p = sf::Mouse::getPosition(characterCreationWindow);

                        for (i = flag; i <= 7; i++)
                        {
                            if (button[i].buttonPressed(p))
                            {
                                spot = i;
                                if (flag == 7)
                                {
                                    con.configCharacters();
                                }
                            }
                        }
                        if (button[10].buttonPressed(p))
                        {
                            state = Config::GUIstate::doneState;
                            characterCreationWindow.clear();
                            characterCreationWindow.display();
                            std::cout << "hi" << std::endl;
                        }
                    }
                }
            }
            if (mouseFlag)
            {
                if (event.type == sf::Event::MouseButtonPressed)
                {
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        p2 = sf::Mouse::getPosition(characterCreationWindow);
                        for (h = 0; h <= 10; h++)

                        {
                            if (button[h].buttonPressed(p2))
                            {
                                spotDisplay = h;
                                std::cout << "stuff" << std::endl;
                                displayPlayerBox[0].textBox("ArialCE.ttf", "Birthplace\n" + m[spotDisplay].getLocation() + "\n\nHP\n" + m[spotDisplay].getHealth() + "\n\nAC\n" + m[spotDisplay].getarmor(), 24, sf::Color::Red, posDisplay[0], 200);
                                displayPlayerBox[1].textBox("ArialCE.ttf", "Class\n" + m[spotDisplay].getType() + "\n\nStats\n" + m[spotDisplay].getMods(), 24, sf::Color::Red, posDisplay[6], 200);

                                for (int i = 0; i <= 2; i++)
                                {
                                    characterCreationWindow.draw(displayPlayerBox[i].gettextBox());
                                }

                                characterCreationWindow.display();
                            }
                        }
                        if (button[9].buttonPressed(p))
                        {
                            state = Config::GUIstate::createState;
                            mouseFlag = 0;
                        }
                    }
                }
            }
            switch (state)
            {
            case Config::GUIstate::createState:
                if (event.type == sf::Event::TextEntered)
                {
                    if (event.text.unicode == '\b' && playerInput.end() != playerInput.begin())
                    {
                        std::cout << playerInput << std::endl;
                        playerInput.erase(playerInput.end() - 1);
                    }
                    else
                    {
                        if (flag < 7 && flag > -1)
                        {
                            if (event.text.unicode == '\x2D')
                            {
                                flag--;
                                spot--;
                                playerInput = "-";
                            }
                            else
                            {
                                playerInput += static_cast<char>(event.text.unicode);
                            }

                            if (flag == 1)
                            {
                                n = event.text.unicode;
                                con.ACII(n);
                            }
                            if (event.text.unicode == '\x0D')
                            {
                                flag++;
                                con.array[spot] = playerInput;
                                playerInput = "*";
                                std::cout << flag << std::endl;
                                spot++;
                            }
                        }
                    }
                }
                characterCreationWindow.clear();
                textbox[spot].textBox("ArialCE.ttf", playerInput, 24, sf::Color::Red, pos[spot], posy[spot]);
                for (int i = 0; i <= 10; i++)
                {
                    characterCreationWindow.draw(button[i].getButton());
                }
                for (int i = 0; i <= 7; i++)
                {
                    characterCreationWindow.draw(textbox[i].gettextBox());
                }
                for (int i = 0; i <= 1; i++)
                {
                    characterCreationWindow.draw(choiceBox[i].gettextBox());
                }
                for (int i = 0; i <= 9; i++)
                {
                    characterCreationWindow.draw(playerBox[i].gettextBox());
                }
                characterCreationWindow.display();
                break;

            case Config::GUIstate::doneState:
                for (int i = 0; i <= con.r; i++)
                {
                    con.readText(con.nameArray[i], con.array, con.target);
                }
                arraySize2 = stoi(con.array[0]);
                int ii = 1;

                for (int i = 0; i <= arraySize2 - 1; i++)
                {
                    m[i].setName(con.array[ii++]);
                    m[i].setType(con.array[ii++]);
                    m[i].setLocation(con.array[ii++]);
                    m[i].setarmor(con.array[ii++]);
                    m[i].setHealth(con.array[ii++]);
                    m[i].setMods(con.array[ii++]);
                }
                for (int i = 0; i <= arraySize2 - 1; i++)
                {
                    displayBox[i].textBox("ArialCE.ttf", m[i].getName(), 24, sf::Color::Red, posDisplay[i], 60);
                }
                for (int i = 0; i <= arraySize2 - 1; i++)
                {
                    displaybuttons[i].setButton(75, 50, posDisplay[i], 60, sf::Color::White);
                }
                characterCreationWindow.clear();
                for (int i = 0; i <= arraySize2 - 1; i++)
                {
                    characterCreationWindow.draw(displaybuttons[i].getButton());
                }
                for (int i = 0; i <= 7; i++)
                {
                    characterCreationWindow.draw(displayBox[i].gettextBox());
                }
                characterCreationWindow.draw(button[9].getButton());
                characterCreationWindow.draw(button[10].getButton());
                for (int i = 0; i <= 1; i++)
                {
                    characterCreationWindow.draw(choiceBox[i].gettextBox());
                }
                mouseFlag = 1;

                characterCreationWindow.display();

                break;
            }
        }
    }
    return 0;
}