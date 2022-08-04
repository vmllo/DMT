
#include "GUI.hpp"
#include "Config.hpp"
#include <cmath>
#include <string.h>
#include "Inventory.hpp"
#include "stats.hpp"
#define font "font/ArialCE.ttf"
#define invi "inventory/"
#define chara "Characters_stats/"

int main()
{
    GUI textbox[15];
    GUI playerBox[15];
    GUI choiceBox[15];
    GUI button[20];
    GUI displayBox[15];
    GUI displaybuttons[15];
    GUI displayPlayerBox[20];
    GUI inven[200];
    Inventory inv;
    Config con;
    sf::RectangleShape background;
    background.setFillColor(sf::Color::Black);
    int pos[12] = {650, 650, 650, 650, 650, 300, 300, 300, 300, 300, 300, 200};
    int posLetters[12] = {550, 550, 520, 550, 550, 200, 200, 200, 200, 200, 200, 150};
    int posy[12] = {20, 100, 200, 300, 400, 20, 100, 200, 300, 400, 500, 600};
    int size[12] = {200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 200, 500};
    int posDisplay[7] = {150, 250, 350, 450, 550, 650};
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
    int loc = 100;
    char invFlag = 0;
    int noob = 0;
    int parsespot = 0;
    Creature m[arraySize2];
    unsigned int state = Config::GUIstate::createState;
    con.init(30, 30, 30, 30, 30, 30, 50, 150, 250, 350, 450, 550);
    choiceBox[0].textBox(font, "Create", 24, sf::Color::Red, 30, con.creaty);
    choiceBox[1].textBox(font, "Done", 24, sf::Color::Red, 30, con.doney);
    choiceBox[2].textBox(font, "Load", 24, sf::Color::Red, 30, con.loady);
    choiceBox[3].textBox(font, "Load Existing", 24, sf::Color::Red, 30, con.loadey);
    choiceBox[4].textBox(font, "Configure", 24, sf::Color::Red, 30, con.configy);
    choiceBox[5].textBox(font, "Inventory", 24, sf::Color::Red, 30, con.invy);
    button[12].setButton(150, 50, 30, 450, sf::Color::White);      // configure
    button[13].setButton(75, 50, 30, 50, sf::Color::White);        // create
    button[14].setButton(50, 50, 30, 150, sf::Color::White);       // done
    button[15].setButton(50, 50, 30, 250, sf::Color::White);       // load
    button[16].setButton(150, 50, 30, 350, sf::Color::White);      // load existing
    button[17].setButton(150, 50, 30, con.invy, sf::Color::White); // inventory

    for (int i = 0; i <= 11; i++)
    {
        playerBox[i].textBox(font, con.target[i], 24, sf::Color::Red, posLetters[i], posy[i]);
    }

    for (int i = 0; i <= 11; i++)
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

                        for (i = flag; i <= 12; i++)
                        {
                            if (button[i].buttonPressed(p))
                            {
                                spot = i;
                                if (flag == 12)
                                {
                                    con.configCharacters(chara, 1);
                                    confirm = 1;
                                }
                            }
                        }
                        if (button[14].buttonPressed(p))
                        {
                            flag = 0;
                            spot = 0;
                            std::fill_n(con.dumbassKey, 100, "");
                            con.n = "";
                        }
                        if (confirm)
                        {
                            if (button[15].buttonPressed(p))
                            {
                                mouseFlag = 1;
                                displayFlag = 1;
                                con.configCharacters(chara, 0);
                                characterCreationWindow.clear();
                                mft = 0;
                                fillari = 0;
                                state = Config::GUIstate::doneState;
                            }
                        }
                        if (button[16].buttonPressed(p))
                        {
                            mouseFlag = 1;
                            displayFlag = 1;
                            mft = 0;
                            fillari = 0;
                            noob = 0;
                            invFlag = 1;
                            characterCreationWindow.clear();
                            state = Config::GUIstate::doneState;
                        }
                        if (button[17].buttonPressed(p))
                        {
                            if (invFlag)
                            {
                                state = Config::GUIstate::invState;
                            }
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
                                displayPlayerBox[0].textBox(font, "Type\n" + m[spotDisplay].getType(), 35, sf::Color::Red, 650, 150);
                                displayPlayerBox[1].textBox(font, "Birthplace\n" + m[spotDisplay].getLocation(), 35, sf::Color::Red, 650, 250);
                                displayPlayerBox[2].textBox(font, "Armor\n" + m[spotDisplay].getarmor(), 35, sf::Color::Red, 650, 350);
                                displayPlayerBox[3].textBox(font, "Health\n" + m[spotDisplay].getHealth(), 35, sf::Color::Red, 650, 450);
                                displayPlayerBox[4].textBox(font, "STR: " + m[spotDisplay].getStr(), 35, sf::Color::Red, 350, 150);
                                displayPlayerBox[5].textBox(font, "DEX: " + m[spotDisplay].getDex(), 35, sf::Color::Red, 350, 200);
                                displayPlayerBox[6].textBox(font, "CON: " + m[spotDisplay].getCon(), 35, sf::Color::Red, 350, 250);
                                displayPlayerBox[7].textBox(font, "INT: " + m[spotDisplay].getInti(), 35, sf::Color::Red, 350, 300);
                                displayPlayerBox[8].textBox(font, "WIS: " + m[spotDisplay].getWis(), 35, sf::Color::Red, 350, 350);
                                displayPlayerBox[9].textBox(font, "CHA: " + m[spotDisplay].getCha(), 35, sf::Color::Red, 350, 400);
                            }
                        }
                        if (button[9].buttonPressed(p2))
                        {
                            stuff = 1;
                        }
                        if (button[13].buttonPressed(p2))
                        {
                            state = Config::GUIstate::createState;
                            flag = 0;
                            spot = 0;
                            confirm = 0;
                            std::fill_n(con.dumbassKey, 100, "");
                            con.n = "";
                            mouseFlag = 0;
                        }
                        if (button[17].buttonPressed(p))
                        {
                            if (invFlag)
                            {
                                state = Config::GUIstate::invState;
                            }
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
                        if (flag == 0)
                            std::fill_n(con.dumbassKey, n - 1, "");
                        playerInput.erase(playerInput.end() - 1);
                    }
                    else
                    {
                        if (flag < 12 && flag > -1)
                        {
                            if (event.text.unicode == '\x5D')
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
                                std::cout << n << std::endl;
                                n = event.text.unicode;
                                con.ACII(n);
                            }
                            if (event.text.unicode == '\x0D')
                            {
                                flag++;
                                con.array[spot] = playerInput;
                                playerInput = "*";
                                spot++;
                                std::cout << spot << std::endl;
                            }
                        }
                    }
                }
                characterCreationWindow.clear();
                textbox[spot].textBox(font, playerInput, 24, sf::Color::Red, pos[spot], posy[spot]);
                button[11].setButton(500, 50, 200, 600, sf::Color::White);
                for (int i = 0; i <= 17; i++)
                {
                    characterCreationWindow.draw(button[i].getButton());
                }
                for (int i = 0; i <= 11; i++)
                {
                    characterCreationWindow.draw(textbox[i].gettextBox());
                }
                for (int i = 0; i <= 5; i++)
                {
                    characterCreationWindow.draw(choiceBox[i].gettextBox());
                }
                for (int i = 0; i <= 11; i++)
                {
                    characterCreationWindow.draw(playerBox[i].gettextBox());
                }
                characterCreationWindow.display();

                break;
            case Config::GUIstate::invState:
                if (event.type == sf::Event::TextEntered)
                {
                    if (event.text.unicode == '\b' && playerInput.end() != playerInput.begin())
                    {
                        if (flag == 0)
                            std::fill_n(con.dumbassKey, n - 1, "");
                        playerInput.erase(playerInput.end() - 1);
                    }
                    else
                    {
                        if (event.text.unicode == '\x5D')
                        {
                            flag--;
                            spot--;
                            playerInput = "-";
                        }
                        else
                        {
                            playerInput += static_cast<char>(event.text.unicode);
                        }
                        if (event.text.unicode == '\x0D')
                        {
                            flag++;
                            loc += 50;
                            inven[spot].textBox(font, playerInput, 24, sf::Color::Red, 200, loc);
                            con.arrayInv[spot] = playerInput;
                            playerInput = "";
                            std::cout << flag << std::endl;
                            spot++;
                        }
                    }
                }
                characterCreationWindow.clear();
                button[11].setButton(500, 50, 250, 800, sf::Color::White);
                textbox[0].textBox(font, playerInput, 24, sf::Color::Red, 250, 800);
                button[17].setButton(150, 50, 30, 800, sf::Color::White); // inventory
                choiceBox[5].textBox(font, "Inventory", 24, sf::Color::Red, 30, 800);
                characterCreationWindow.draw(button[12].getButton());
                characterCreationWindow.draw(button[13].getButton());
                characterCreationWindow.draw(button[15].getButton());
                characterCreationWindow.draw(button[16].getButton());
                characterCreationWindow.draw(button[17].getButton());
                characterCreationWindow.draw(button[11].getButton());
                characterCreationWindow.draw(textbox[0].gettextBox());
                for (int i = 0; i <= arraySize2; i++)
                {
                    displayBox[i].textBox(font, m[i].getName(), 24, sf::Color::Red, posDisplay[i], 60);
                }
                for (int i = 0; i <= 5; i++)
                {
                    if (i != 1)
                        characterCreationWindow.draw(choiceBox[i].gettextBox());
                }
                for (int i = 0; i <= spot; i++)
                {
                    characterCreationWindow.draw(inven[i].gettextBox());
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

                characterCreationWindow.display();

                break;
            case Config::GUIstate::doneState:

                if (stuff)
                {
                    stuff = 0;
                    if (con.readText(chara, "config.txt", con.array, con.target, 0, 0, 0, 0))
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
                for (fillari; fillari <= arraySize2 - 1; fillari++)
                {
                    if (fillari == counter)
                    {
                        parsespot += 11;
                        counter++;
                    }
                    con.readText(chara, con.nameArray[fillari], con.array, con.target, 1, parsespot, 0, 0);
                }

                int ii = 0;
                for (mft; mft <= arraySize2; mft++)
                {
                    m[mft].setName(con.outArray[ii++]);
                    m[mft].setType(con.outArray[ii++]);
                    m[mft].setLocation(con.outArray[ii++]);
                    m[mft].setarmor(con.outArray[ii++]);
                    m[mft].setHealth(con.outArray[ii++]);
                    m[mft].setStr(con.outArray[ii++]);
                    m[mft].setDex(con.outArray[ii++]);
                    m[mft].setCon(con.outArray[ii++]);
                    m[mft].setInt(con.outArray[ii++]);
                    m[mft].setWis(con.outArray[ii++]);
                    m[mft].setCha(con.outArray[ii++]);
                }

                characterCreationWindow.clear();
                for (int i = 0; i <= arraySize2; i++)
                {
                    displayBox[i].textBox(font, m[i].getName(), 24, sf::Color::Red, posDisplay[i], 60);
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

                for (int i = 0; i <= 10; i++)
                {

                    characterCreationWindow.draw(displayPlayerBox[i].gettextBox());
                }

                characterCreationWindow.draw(button[12].getButton());
                characterCreationWindow.draw(button[13].getButton());
                characterCreationWindow.draw(button[14].getButton());
                characterCreationWindow.draw(button[15].getButton());
                characterCreationWindow.draw(button[16].getButton());
                characterCreationWindow.draw(button[17].getButton());

                for (int i = 0; i <= 5; i++)
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