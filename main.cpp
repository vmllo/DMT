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
    GUI button[12];
    GUI displayBox[7];
    GUI displaybuttons[7];
    GUI displayPlayerBox[2];
    Config con;
    sf::RectangleShape background;
    background.setFillColor(sf::Color::Black);
    int pos[8] = {325, 650, 300, 250, 600, 300, 300};
    int posLetters[7] = {250, 515, 180, 150, 515, 200};
    int posy[8] = {60, 200, 200, 300, 300, 400, 600};
    int size[8] = {200, 200, 200, 200, 200, 500, 500};
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
    int stuff = 1;
    sf::Vector2i p;
    sf::Vector2i p2;
    int i;
    int h;
    int flag = 0;
    int confirm = 0;
    int mouseFlag = 0;
    sf::String newName;
    unsigned int n;
    const char *stuff2;
    int arraySize2 = 20;
    int mft = 0;
    int fillari = 0;
    int counter = 0;
    int displayi = 0;
    int displayFlag = 1;
    int debugi = 0;
    int parsespot = 0;
    Creature m[arraySize2];
    unsigned int state = Config::GUIstate::createState;
    choiceBox[0].textBox("ArialCE.ttf", "Display shit", 24, sf::Color::Red, 700, 800);
    choiceBox[1].textBox("ArialCE.ttf", "Create", 24, sf::Color::Red, 300, 700);
    choiceBox[2].textBox("ArialCE.ttf", "Done", 24, sf::Color::Red, 400, 700);
    choiceBox[3].textBox("ArialCE.ttf", "Load", 24, sf::Color::Red, 500, 700);
    choiceBox[4].textBox("ArialCE.ttf", "Load Existing", 24, sf::Color::Red, 600, 700);
    button[9].setButton(75, 50, 700, 800, sf::Color::White);
    button[10].setButton(75, 50, 300, 700, sf::Color::White);
    button[11].setButton(50, 50, 400, 700, sf::Color::White);
    button[12].setButton(50, 50, 500, 700, sf::Color::White);
    button[13].setButton(150, 50, 600, 700, sf::Color::White);

    for (int i = 0; i <= 5; i++)
    {
        playerBox[i].textBox("ArialCE.ttf", con.target[i], 24, sf::Color::Red, posLetters[i], posy[i]);
    }

    for (int i = 0; i <= 8; i++)
    {
        button[i].setButton(size[i], 50, pos[i], posy[i], sf::Color::White);
    }
    characterCreationWindow.clear();
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
                                if (flag == 6)
                                {
                                    con.configCharacters(1);
                                    confirm = 1;
                                }
                            }
                        }
                        if (button[11].buttonPressed(p))
                        {
                            flag = 0;
                            spot = 0;
                            std::fill_n(con.dumbassKey, 100, "");
                            con.n = "";
                        }
                        if (confirm)
                        {
                            if (button[12].buttonPressed(p))
                            {
                                mouseFlag = 1;
                                displayFlag = 1;
                                con.configCharacters(0);
                                characterCreationWindow.clear();
                                state = Config::GUIstate::doneState;
                            }
                        }
                        if (button[13].buttonPressed(p))
                        {
                            mouseFlag = 1;
                            displayFlag = 1;
                            characterCreationWindow.clear();
                            state = Config::GUIstate::doneState;
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
                        for (h = 0; h <= con.r; h++)
                        {
                            if (displaybuttons[h].buttonPressed(p2))
                            {
                                spotDisplay = h;
                                displayPlayerBox[0].textBox("ArialCE.ttf", "Birthplace\n" + m[spotDisplay].getLocation() + "\n\nHP\n" + m[spotDisplay].getHealth() + "\n\nAC\n" + m[spotDisplay].getarmor(), 35, sf::Color::Red, 250, 200);
                                displayPlayerBox[1].textBox("ArialCE.ttf", "Class\n" + m[spotDisplay].getType() + "\n\nStats\n" + m[spotDisplay].getMods(), 35, sf::Color::Red, 550, 200);
                            }
                        }
                        if (button[9].buttonPressed(p2))
                        {
                            stuff = 1;
                        }
                        if (button[10].buttonPressed(p2))
                        {
                            state = Config::GUIstate::createState;
                            flag = 0;
                            spot = 0;
                            confirm = 0;
                            std::fill_n(con.dumbassKey, 100, "");
                            con.n = "";
                            mouseFlag = 0;
                        }
                    }
                }
            }
            displayFlag = 0;
            if (event.type == sf::Event::Closed)
            {
                printf("noob");
                characterCreationWindow.close();
            }         
            switch (state)
            {
            case Config::GUIstate::createState:
                if (event.type == sf::Event::TextEntered)
                {
                    if (event.text.unicode == '\b' && playerInput.end() != playerInput.begin())
                    {
                        std::cout << playerInput << std::endl;
                        if (flag == 0)
                            std::fill_n(con.dumbassKey, n - 1, "");
                        playerInput.erase(playerInput.end() - 1);
                    }
                    else
                    {
                        if (flag < 6 && flag > -1)
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
                            if (flag == 0)
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
                for (int i = 0; i <= 13; i++)
                {
                    characterCreationWindow.draw(button[i].getButton());
                }
                for (int i = 0; i <= 7; i++)
                {
                    characterCreationWindow.draw(textbox[i].gettextBox());
                }
                for (int i = 0; i <= 4; i++)
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

                if (stuff)
                {
                    stuff = 0;
                    if (con.readText("config.txt", con.array, con.target, 0, 0, 0))
                    {
                        int ll = 1;
                        for (int l = 0; l <= con.r; l++)
                        {
                            con.nameArray[l] = con.array[ll];
                            ll++;
                        }
                    }
                }
                arraySize2 = con.r;
                if (displayFlag)
                {
                    std::fill_n(con.array, 100, "");
                    displayFlag = 0;
                }
                for (fillari; fillari <= arraySize2; fillari++)
                {
                    if (fillari == counter)
                    {
                        parsespot += 6;
                        counter++;
                    }
                    con.readText(con.nameArray[fillari], con.array, con.target, 1, parsespot, 0);
                }
                int ii = 0;
                for (mft; mft <= arraySize2; mft++)
                {
                    m[mft].setName(con.outArray[ii++]);
                    m[mft].setType(con.outArray[ii++]);
                    m[mft].setLocation(con.outArray[ii++]);
                    m[mft].setarmor(con.outArray[ii++]);
                    m[mft].setHealth(con.outArray[ii++]);
                    m[mft].setMods(con.outArray[ii++]);
                }

                characterCreationWindow.clear();

                for (int i = 0; i <= arraySize2; i++)
                {
                    displayBox[i].textBox("ArialCE.ttf", m[i].getName(), 24, sf::Color::Red, posDisplay[i], 60);
                }
                for (int i = 0; i <= arraySize2; i++)
                {
                    displaybuttons[i].setButton(75, 50, posDisplay[i], 60, sf::Color::White);
                }
                for (int i = 0; i <= arraySize2; i++)
                {
                    characterCreationWindow.draw(displaybuttons[i].getButton());
                }
                for (int i = 0; i <= arraySize2; i++)
                {
                    characterCreationWindow.draw(displayBox[i].gettextBox());
                }
                for (int i = 0; i <= arraySize2; i++)
                {

                    characterCreationWindow.draw(displayPlayerBox[i].gettextBox());
                }
                characterCreationWindow.draw(button[9].getButton());
                characterCreationWindow.draw(button[10].getButton());
                characterCreationWindow.draw(button[11].getButton());
                characterCreationWindow.draw(button[12].getButton());
                characterCreationWindow.draw(button[13].getButton());
                for (int i = 0; i <= 4; i++)
                {
                    characterCreationWindow.draw(choiceBox[i].gettextBox());
                }
                characterCreationWindow.display();
                break;
            }
        }
    }
    return 0;
}