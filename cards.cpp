/**
 *
 *       \file       cards.cpp
 *
 *       \brief      includes
 *
 *       \version    0.1
 *       \date       Wedenesday, October 14 2015 11:58 PT\n
 *       Compiler    g++
 *
 *       \author     Jasvir Singh Grewal, jasvirsinghgrewal1991@gmail.com\n
 *                   Mayank Kasturia, mayankkasturia1993@gmail.com
 *
 *       License     GNU General Public License
 *
 *       \source     https://github.com/jasvir99/Journey_CSULB
 */

#include "cards.h"
#include "QDebug"
#include "chipbox.h"
#include <map>
#include <utility>
#include "discardcard.h"

//Initializing static data members

int GamePlay::total_points[3] = {};
//int GamePlay::cards_in_hand[5] = {};
int GamePlay::top_card_in_hand = 0;
int GamePlay::top_card_in_hand_ai1 = 0;
int GamePlay::top_card_in_hand_ai2 = 0;
int GamePlay::craft_chips[3] = {};
int GamePlay::learning_chips[3] = {10,10,10};
int GamePlay::integrity_chips[3] = {10,10,10};
int GamePlay::quality_points[3] = {10,10,10};

std::map<int, GamePlay*> Cards::play;

QList<int> empty_list()
{
    //special function to initialize empty qlist
    QList<int> list;
    return list;
}

QList<int> GamePlay::cards_in_hand = empty_list();
QList<int> GamePlay::ai1_hand = empty_list();
QList<int> GamePlay::ai2_hand = empty_list();
QList<int> GamePlay::discarded_card_deck = empty_list();

QList<int> init_complete_deck()
{
    QList<int> deck;
    for(int i = 0; i < 51; i++)
    {
        deck.insert(i,i+1);
    }

    return deck;
}

QList<int> GamePlay::complete_card_deck = init_complete_deck();

GamePlay::GamePlay()
{

    QTime time = QTime::currentTime();
    qsrand((uint)time.second());
}

Cards::Cards()
{
     play[0] = new Cecs105();
}

bool GamePlay::already_have_card(int card_list_array[], int card_id,
                                 int array_size)
{
    bool card_in_list = false;
    for (int j=1;j <= array_size;j++)
    {
        if(card_list_array[j] == card_id)
        {
           card_in_list = true;
           break;
        }
    }

    return card_in_list;
}

int GamePlay::gen_rand_number(int max)
{
    /*
     * function to generate random number b/w 0 and max
     */

    int b = qrand() % max;
    return b;
}

int GamePlay::randomize_deck()
{
    int deck_size = complete_card_deck.size();
    if(deck_size == 0)
    {
        deck_size = 51;
    }
    for(int i = 0; i < complete_card_deck.size(); i++)
    {
        int pos =  gen_rand_number(deck_size);
        int temp = complete_card_deck[i];
        complete_card_deck[i] = complete_card_deck[pos];
        complete_card_deck[pos] = temp;
    }

    return 0;
}

void Cards::initialize_map_with_objects()
{
    play.insert(std::make_pair(1, new Maths122()));
    play.insert(std::make_pair(2, new LunchAtBrawtrustHall()));
    play.insert(std::make_pair(3, new ResearchOnCompilers()));
    play.insert(std::make_pair(4, new Cecs174()));
    play.insert(std::make_pair(5, new Cecs100()));
    play.insert(std::make_pair(6, new ExerciseInRecreation()));
    play.insert(std::make_pair(7, new FindLabUsingElevators));
    play.insert(std::make_pair(8, new EnjoyPeace));
    play.insert(std::make_pair(9, new ParkingViolation));
    play.insert(std::make_pair(10, new SayGoodByeToProfessor));
    play.insert(std::make_pair(11, new JoiningEatOrSoccer));
    play.insert(std::make_pair(12, new GetLateForClass));
    play.insert(std::make_pair(13, new PlayBigGame));
    play.insert(std::make_pair(14, new PassMath123()));
    play.insert(std::make_pair(15, new PassPhysics151()));
    play.insert(std::make_pair(16, new PassKin253()));
    play.insert(std::make_pair(17, new LearnNetbeans()));
    play.insert(std::make_pair(18, new ChooseMajor()));
    play.insert(std::make_pair(19, new ScoreGoal()));
    play.insert(std::make_pair(20, new MakeDeansList()));
    play.insert(std::make_pair(21, new PassSoccerClass()));
    play.insert(std::make_pair(22, new FallInPond()));
    play.insert(std::make_pair(23, new UseNewLaptop()));
    play.insert(std::make_pair(24, new MeetDean()));
    play.insert(std::make_pair(25, new CrashProgram()));
    play.insert(std::make_pair(26, new PressFloorButton()));
    play.insert(std::make_pair(27, new MakeAlarmBuzz()));
    play.insert(std::make_pair(28, new MeetProfessorEnglert()));
    play.insert(std::make_pair(29, new BeSoccerGoalie()));
    play.insert(std::make_pair(30, new TakeElectiveClass()));
    play.insert(std::make_pair(31, new MeetProfessorHoffman()));
    play.insert(std::make_pair(32, new GoToOutpost()));
    play.insert(std::make_pair(33, new AttendOralCommunication()));
    play.insert(std::make_pair(34, new PassChemsitry111()));
    play.insert(std::make_pair(35, new LearnLinux()));
    play.insert(std::make_pair(36, new MakeFriend()));
    play.insert(std::make_pair(37, new EnjoyNature()));
    play.insert(std::make_pair(38, new ParkInStudentParking));
    play.insert(std::make_pair(39, new EnjoyPeace));
    play.insert(std::make_pair(40, new EnjoyPeace));
    play.insert(std::make_pair(41, new EnjoyPeace));
    play.insert(std::make_pair(42, new EnjoyPeace));
    play.insert(std::make_pair(43, new EnjoyPeace));
    play.insert(std::make_pair(44, new EnjoyPeace));
    play.insert(std::make_pair(45, new EnjoyPeace));
    play.insert(std::make_pair(46, new EnjoyPeace));
    play.insert(std::make_pair(47, new EnjoyPeace));
    play.insert(std::make_pair(48, new EnjoyPeace));
    play.insert(std::make_pair(49, new EnjoyPeace));
    play.insert(std::make_pair(50, new EnjoyPeace));
}

bool GamePlay::main_play(int player)
{
    //defination of virtual function;
    return true;
}

bool Cecs105::main_play(int player)
{
    qDebug()<<"This is cecs105";
    if(pre_requisite_satified(player))
    {
        qDebug()<<"Success";
        learning_chips[player] += 1;
        return true;
    }
    else
    {
        qDebug()<<"fail";
        return false;
    }
}

bool Cecs105::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    if(location == 14 || location == 17)
        return true;
    else
        return false;
}

bool Maths122::main_play(int player)
{
    qDebug()<<"This is maths122";
    if(pre_requisite_satified(player))
    {
        qDebug()<<"Success";
        if(player == MainWindow::main_player_id)
        {
            ChipBox::craft_enabled = false;
            ChipBox chip(true);
            if(ChipBox::got_integrity_chip)
            {
                integrity_chips[player] += 1;
                ChipBox::got_integrity_chip = false;
            }
            else if(ChipBox::got_craft_chip)
            {
                craft_chips[player] += 1;
                ChipBox::got_craft_chip = false;
            }
            else if(ChipBox::got_learning_chip)
            {
                learning_chips[player] += 1;
                ChipBox::got_learning_chip = false;
            }
        }

        else
        {
            QList<int> enabled_chips;
            enabled_chips.insert(0,1);
            enabled_chips.insert(1,2);
            ChipBox chip(false);
            chip.chip_selection_ai(enabled_chips,player);
        }
        ChipBox::craft_enabled = true;

        return true;
    }
    else
    {
        qDebug()<<"fail";
        return false;
    }
}

bool Maths122::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    if(location == 7)
        return true;
    else
        return false;
}

bool LunchAtBrawtrustHall::main_play(int player)
{
    qDebug()<<"This is lunch";
    if(pre_requisite_satified(player))
    {
        qDebug()<<"Success";
        craft_chips[player] += 1;
        return true;
    }
    else
    {
        qDebug()<<"fail";
        return false;
    }
}

bool LunchAtBrawtrustHall::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    if(location == 9)
        return true;
    else
        return false;
}

bool ResearchOnCompilers::main_play(int player)
{
    qDebug()<<"This is research";
    if(pre_requisite_satified(player))
    {
        qDebug()<<"Success";
        learning_chips[player] += 1;
        return true;
    }
    else
    {
        qDebug()<<"fail";
        return false;
    }
}

bool ResearchOnCompilers::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    if(location == 7)
        return true;
    else
        return false;
}

bool Cecs174::main_play(int player)
{
    qDebug()<<"This is cecs174";
    if(pre_requisite_satified(player))
    {
        qDebug()<<"Success";
        learning_chips[player] += 1;
        return true;
    }
    else
    {
        qDebug()<<"fail";
        return false;
    }
}

bool Cecs174::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    if(location == 14)
        return true;
    else
        return false;
}

bool Cecs100::main_play(int player)
{
    qDebug()<<"This is cecs100";
    if(pre_requisite_satified(player))
    {
        qDebug()<<"Success";
        craft_chips[player] += 1;
        return true;
    }
    else
    {
        qDebug()<<"fail";
        return false;
    }
}

bool Cecs100::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    if(location == 17)
        return true;
    else
        return false;
}

bool ExerciseInRecreation::main_play(int player)
{
    qDebug()<<"This is exercise";
    if(pre_requisite_satified(player))
    {
        qDebug()<<"Success";
        integrity_chips[player] += 1;
        return true;
    }
    else
    {
        qDebug()<<"fail";
        return false;
    }
}

bool ExerciseInRecreation::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    if(location == 5)
        return true;
    else
        return false;
}

bool FindLabUsingElevators::main_play(int player)
{
    qDebug()<<"This is findlab";
    if(pre_requisite_satified(player))
    {
        qDebug()<<"Success";
        integrity_chips[player] += 1;
        return true;
    }
    else
    {
        qDebug()<<"fail";
        return false;
    }
}

bool FindLabUsingElevators::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    if(location == 16)
        return true;
    else
        return false;
}

bool EnjoyPeace::main_play(int player)
{
    qDebug()<<"This is peace";
    if(pre_requisite_satified(player))
    {
        qDebug()<<"Success";
        if(player == MainWindow::main_player_id)
        {
            ChipBox::craft_enabled = false;
            ChipBox chip(true);
            if(ChipBox::got_integrity_chip)
            {
                integrity_chips[player] += 1;
                ChipBox::got_integrity_chip = false;
            }
            else if(ChipBox::got_craft_chip)
            {
                craft_chips[player] += 1;
                ChipBox::got_craft_chip = false;
            }
            else if(ChipBox::got_learning_chip)
            {
                learning_chips[player] += 1;
                ChipBox::got_learning_chip = false;
            }
        }

        else
        {
            QList<int> enabled_chips;
            enabled_chips.insert(0,1);
            enabled_chips.insert(1,2);
            ChipBox chip(false);
            chip.chip_selection_ai(enabled_chips,player);
        }
        ChipBox::craft_enabled = true;
        return true;
    }
    else
    {
        qDebug()<<"fail";
        return false;
    }
}

bool EnjoyPeace::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    if(location == 1)
        return true;
    else
        return false;
}

bool ParkingViolation::main_play(int player)
{
    qDebug()<<"This is Parking";
    if(pre_requisite_satified(player))
    {
        qDebug()<<"Success";
        learning_chips[player] += 1;
        if(player == MainWindow::main_player_id)
        {
            DiscardCard discard;
            if(DiscardCard::card_discarded)
                learning_chips[player] += 1;
        }
        return true;
    }
    else
    {
        qDebug()<<"fail";
        return false;
    }
}

bool ParkingViolation::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    if(location == 6)
        return true;
    else
        return false;
}

bool JoiningEatOrSoccer::main_play(int player)
{
    qDebug()<<"This is eatorsoccer";
    if(pre_requisite_satified(player))
    {
        qDebug()<<"Success";
        if(player == MainWindow::main_player_id)
        {
            ChipBox::integrity_enabled = false;
            ChipBox chip(true);
            if(ChipBox::got_integrity_chip)
            {
                integrity_chips[player] += 1;
                ChipBox::got_integrity_chip = false;
            }
            else if(ChipBox::got_craft_chip)
            {
                craft_chips[player] += 1;
                ChipBox::got_craft_chip = false;
            }
            else if(ChipBox::got_learning_chip)
            {
                learning_chips[player] += 1;
                ChipBox::got_learning_chip = false;
            }
        }
        else
        {
            QList<int> enabled_chips;
            enabled_chips.insert(0,1);
            enabled_chips.insert(1,3);
            ChipBox chip(false);
            chip.chip_selection_ai(enabled_chips,player);
        }
        ChipBox::integrity_enabled = true;
        return true;
    }
    else
    {
        qDebug()<<"fail";
        return false;
    }
}

bool JoiningEatOrSoccer::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    if(location == 18)
        return true;
    else
        return false;
}

bool GetLateForClass::main_play(int player)
{
    qDebug()<<"This is late for class";
    if(pre_requisite_satified(player))
    {
        qDebug()<<"Success";
        craft_chips[player] += 1;
        MainWindow window(false);
        window.relocate(20, MainWindow::players[player],
                             MainWindow::y_offsets[player]);
        return true;
    }
    else
    {
        qDebug()<<"fail";
        return false;
    }
}

bool GetLateForClass::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    if(location != 6)
        return true;
    else
        return false;
}

bool SayGoodByeToProfessor::main_play(int player)
{
    qDebug()<<"This is good to professor";
    if(pre_requisite_satified(player))
    {
        qDebug()<<"Success";
        quality_points[player] += 10;
        return true;
    }

    else
    {
        qDebug()<<"fail";
        remove_game_card_from_hand(player);
        return false;
    }
}

bool SayGoodByeToProfessor::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    int learning = learning_chips[player];
    int craft = craft_chips[player];
    int integrity = integrity_chips[player];
    if(location == 13 && learning >= 6 && craft >= 6 && integrity >= 6)
        return true;
    else
        return false;
}


bool PassMath123::main_play(int player)
{
    qDebug()<<"This is pass math 123";
    if(pre_requisite_satified(player))
    {
        qDebug()<<"Success";
        quality_points[player] += 5;
        return true;
    }
    else
    {
        qDebug()<<"fail";
        quality_points[player] -= 3;
        remove_game_card_from_hand(player);
        return false;
    }
}

bool PassMath123::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    int learning = learning_chips[player];
    if((location == 14 || location == 17) && learning >= 5)
        return true;
    else
        return false;
}


bool PlayBigGame::main_play(int player)
{
    qDebug()<<"This is play big game";
    if(pre_requisite_satified(player))
    {
        qDebug()<<"Success";
        craft_chips[player] += 1;
        MainWindow window(false);
        window.relocate(20, MainWindow::players[player],
                        MainWindow::y_offsets[player]);
        return true;
    }
    else
    {
        qDebug()<<"fail";
        return false;
    }
}

bool PlayBigGame::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    if(location == 3)
        return true;
    else
        return false;
}

bool PassPhysics151::main_play(int player)
{
    qDebug()<<"This is pass physics";
    if(pre_requisite_satified(player))
    {
        qDebug()<<"Success";
        quality_points[player] += 5;
        return true;
    }
    else
    {
        qDebug()<<"fail";
        quality_points[player] -= 3;
        return false;
    }
}

bool PassPhysics151::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    int craft = craft_chips[player];
    if(location == 17 && craft >= 3)
        return true;
    else
        return false;
}

bool PassKin253::main_play(int player)
{
    qDebug()<<"This is passkin";
    if(pre_requisite_satified(player))
    {
        qDebug()<<"Success";
        craft_chips[player] += 2;
        return true;
    }
    else
    {
        qDebug()<<"fail";
        MainWindow window(false);
        window.relocate(13, MainWindow::players[player],
                        MainWindow::y_offsets[player]);
        return false;
    }
}


bool PassKin253::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    int craft = craft_chips[player];
    if(location == 0 &&  craft >= 2)
        return true;
    else
        return false;
}

bool LearnNetbeans::main_play(int player)
{
    qDebug()<<"This is net beans";
    if(pre_requisite_satified(player))
    {
        qDebug()<<"Success";
        quality_points[player] += 5;
        return true;
    }
    else
    {
        qDebug()<<"fail";
        quality_points[player] -= 3;
        return false;
    }
}

bool LearnNetbeans::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    if(location == 20)
        return true;
    else
        return false;
}


bool ChooseMajor::main_play(int player)
{
    qDebug()<<"This is choose major";
    if(pre_requisite_satified(player))
    {
        qDebug()<<"Success";
        quality_points[player] += 5;
        return true;
    }
    else
    {
        qDebug()<<"fail";
        quality_points[player] -= 3;
        return false;
    }
}

bool ChooseMajor::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    int integrity = integrity_chips[player];
    if(location == 19 && integrity >= 3)
        return true;
    else
        return false;
}

bool ScoreGoal::main_play(int player)
{
    qDebug()<<"This is score goal";
    if(pre_requisite_satified(player))
    {
        qDebug()<<"Success";
        quality_points[player] += 5;
        integrity_chips[player] += 1;
        return true;
    }
    else
    {
        qDebug()<<"fail";
        MainWindow window(false);
        window.relocate(2, MainWindow::players[player],
                        MainWindow::y_offsets[player]);
        return false;
    }
}

bool ScoreGoal::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    int craft = craft_chips[player];
    if(location == 0 && craft >= 3)
        return true;
    else
        return false;
}

bool MakeDeansList::main_play(int player)
{
    qDebug()<<"This is make dean list";
    if(pre_requisite_satified(player))
    {
        qDebug()<<"Success";
        quality_points[player] += 5;
        return true;
    }
    else
    {
        qDebug()<<"fail";
        MainWindow window(false);
        window.relocate(2, MainWindow::players[player],
                        MainWindow::y_offsets[player]);
        return false;
    }
}

bool MakeDeansList::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    int learning = learning_chips[player];
    if((location == 12 || location == 15) && learning >= 6)
        return true;
    else
        return false;
}

bool PassSoccerClass::main_play(int player)
{
    qDebug()<<"This is pass soccer class";
    if(pre_requisite_satified(player))
    {
        qDebug()<<"Success";
        quality_points[player] += 5;
        return true;
    }
    else
    {
        qDebug()<<"fail";
        quality_points[player] -= 3;
        return false;
    }
}

bool PassSoccerClass::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    int craft = craft_chips[player];
    if(location == 0 && craft >= 5)
        return true;
    else
        return false;
}

bool FallInPond::main_play(int player)
{
    qDebug()<<"This is fallinpond";
    if(pre_requisite_satified(player))
    {
        qDebug()<<"Success";
        integrity_chips[player] += 1;
        craft_chips[player] += 1;
        return true;
    }
    else
    {
        qDebug()<<"fail";
        MainWindow window(false);
        window.relocate(20, MainWindow::players[player],
                        MainWindow::y_offsets[player]);
        return false;
    }
}

bool FallInPond::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    int learning = learning_chips[player];
    if(location == 1 && learning >= 3)
        return true;
    else
        return false;
}

bool UseNewLaptop::main_play(int player)
{
    qDebug()<<"This is new laptop";
    if(pre_requisite_satified(player))
    {
        qDebug()<<"Success";
        quality_points[player] += 3;
        if(player == MainWindow::main_player_id)
        {
            ChipBox chip(true);
            if(ChipBox::got_integrity_chip)
            {
                integrity_chips[player] += 1;
                ChipBox::got_integrity_chip = false;
            }
            else if(ChipBox::got_craft_chip)
            {
                craft_chips[player] += 1;
                ChipBox::got_craft_chip = false;
            }
            else if(ChipBox::got_learning_chip)
            {
                learning_chips[player] += 1;
                ChipBox::got_learning_chip = false;
            }
        }

        else
        {
            QList<int> enabled_chips;
            enabled_chips.insert(0,1);
            enabled_chips.insert(1,2);
            enabled_chips.insert(2,3);
            ChipBox chip(false);
            chip.chip_selection_ai(enabled_chips,player);
        }
        return true;
    }
    else
    {
        qDebug()<<"fail";
        remove_game_card_from_hand(player);
        return false;
    }
}

bool UseNewLaptop::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    int integrity = integrity_chips[player];
    if(location == 11 && integrity >=4 )
        return true;
    else
        return false;
}

bool MeetDean::main_play(int player)
{
    qDebug()<<"This is meet dean";
    if(pre_requisite_satified(player))
    {
        qDebug()<<"Success";
        quality_points[player] += 5;
        add_game_card_in_hand(player);
        return true;
    }
    else
    {
        qDebug()<<"fail";
        remove_game_card_from_hand(player);
        return false;
    }
}

bool MeetDean::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    int learning = learning_chips[player];
    int craft = craft_chips[player];
    int integrity = integrity_chips[player];
    if((location == 12 || location == 15) && learning >= 3 && craft >= 3 &&
            integrity >= 3)
        return true;
    else
        return false;
}

bool CrashProgram::main_play(int player)
{
    qDebug()<<"This is crash program";
    if(pre_requisite_satified(player))
    {
        qDebug()<<"Success";
        quality_points[player] += 5;
        add_game_card_in_hand(player);
        return true;
    }
    else
    {
        qDebug()<<"fail";
        remove_game_card_from_hand(player);
        return false;
    }
}

bool CrashProgram::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    int learning = learning_chips[player];
    if(location == 20 && learning >= 2)
        return true;
    else
        return false;
}

bool PressFloorButton::main_play(int player)
{
    qDebug()<<"This is press floor button";
    if(pre_requisite_satified(player))
    {
        qDebug()<<"Success";
        craft_chips[player] += 2;
        return true;
    }
    else
    {
        qDebug()<<"fail";
        quality_points[player] -= 2;
        return false;
    }
}

bool PressFloorButton::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    int learning = learning_chips[player];
    if(location == 16 && learning >= 4)
        return true;
    else
        return false;
}

bool MakeAlarmBuzz::main_play(int player)
{
    qDebug()<<"This is make alarm buzz";
    if(pre_requisite_satified(player))
    {
        qDebug()<<"Success";
        craft_chips[player] += 3;
        if(player == MainWindow::main_player_id)
        {
            ChipBox chip(true);
            if(ChipBox::got_integrity_chip)
            {
                integrity_chips[player] += 1;
                ChipBox::got_integrity_chip = false;
            }
            else if(ChipBox::got_craft_chip)
            {
                craft_chips[player] += 1;
                ChipBox::got_craft_chip = false;
            }
            else if(ChipBox::got_learning_chip)
            {
                learning_chips[player] += 1;
                ChipBox::got_learning_chip = false;
            }
        }
        else
        {
            QList<int> enabled_chips;
            enabled_chips.insert(0,1);
            enabled_chips.insert(1,2);
            enabled_chips.insert(2,3);
            ChipBox chip(false);
            chip.chip_selection_ai(enabled_chips,player);
        }
        return true;
    }
    else
    {
        qDebug()<<"fail";
        quality_points[player] -= 2;
        return false;
    }
}

bool MakeAlarmBuzz::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    int craft = craft_chips[player];
    if(location == 18 && craft >= 3)
        return true;
    else
        return false;
}

bool MeetProfessorEnglert::main_play(int player)
{
    qDebug()<<"This is englert";
    if(pre_requisite_satified(player))
    {
        qDebug()<<"Success";
        if(player == MainWindow::main_player_id)
        {
            ChipBox chip(true);
            if(ChipBox::got_integrity_chip)
            {
                integrity_chips[player] += 1;
                ChipBox::got_integrity_chip = false;
            }
            else if(ChipBox::got_craft_chip)
            {
                craft_chips[player] += 1;
                ChipBox::got_craft_chip = false;
            }
            else if(ChipBox::got_learning_chip)
            {
                learning_chips[player] += 1;
                ChipBox::got_learning_chip = false;
            }
        }
        else
        {
            QList<int> enabled_chips;
            enabled_chips.insert(0,1);
            enabled_chips.insert(1,2);
            enabled_chips.insert(2,3);
            ChipBox chip(false);
            chip.chip_selection_ai(enabled_chips,player);
        }

        return true;
    }
    else
    {
        qDebug()<<"fail";
        remove_game_card_from_hand(player);
        return false;
    }
}

bool MeetProfessorEnglert::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    int integrity = integrity_chips[player];
    if((location == 19) && integrity >= 3)
        return true;
    else
        return false;
}

bool BeSoccerGoalie::main_play(int player)
{
    qDebug()<<"This is goalie";
    if(pre_requisite_satified(player))
    {
        qDebug()<<"Success";
        quality_points[player] += 5;
        add_game_card_in_hand(player);
        return true;
    }
    else
    {
        qDebug()<<"fail";
        MainWindow window(false);
        window.relocate(2, MainWindow::players[player],
                        MainWindow::y_offsets[player]);
        return false;
    }
}

bool BeSoccerGoalie::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    int learning = learning_chips[player];
    int craft = craft_chips[player];
    if(location == 0 && learning >= 3 && craft >= 3)
        return true;
    else
        return false;
}

bool TakeElectiveClass::main_play(int player)
{
    qDebug()<<"This is effective class";
    if(pre_requisite_satified(player))
    {
        qDebug()<<"Success";
        learning_chips[player] += 1;
        add_game_card_in_hand(player);
        return true;
    }
    else
    {
        qDebug()<<"fail";
        quality_points[player] -= 2;
        return false;
    }
}

bool TakeElectiveClass::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    int learning = learning_chips[player];
    if(location == 7 && learning >= 2)
        return true;
    else
        return false;
}


bool MeetProfessorHoffman::main_play(int player)
{
    qDebug()<<"This is hoffman";
    if(pre_requisite_satified(player))
    {
        qDebug()<<"Success";
        quality_points[player] += 5;
        add_game_card_in_hand(player);
        add_game_card_in_hand(player);
        return true;
    }
    else
    {
        qDebug()<<"fail";
        quality_points[player] -= 5;
        MainWindow window(false);
        window.relocate(20, MainWindow::players[player],
                        MainWindow::y_offsets[player]);

        return false;
    }
}

bool MeetProfessorHoffman::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    int learning = learning_chips[player];
    if((location == 11 || location == 14 || location == 18 || location == 19 ||
        location == 12 || location == 15 || location == 13 || location == 16 ||
        location  == 17) && learning >= 3)
        return true;
    else
        return false;
}

bool GoToOutpost::main_play(int player)
{
    qDebug()<<"This is outpost";
    if(pre_requisite_satified(player))
    {
        qDebug()<<"Success";
        if(player == MainWindow::main_player_id)
        {
            ChipBox chip(true);
            if(ChipBox::got_integrity_chip)
            {
                integrity_chips[player] += 1;
                ChipBox::got_integrity_chip = false;
            }
            else if(ChipBox::got_craft_chip)
            {
                craft_chips[player] += 1;
                ChipBox::got_craft_chip = false;
            }
            else if(ChipBox::got_learning_chip)
            {
                learning_chips[player] += 1;
                ChipBox::got_learning_chip = false;
            }
        }

        else
        {
            QList<int> enabled_chips;
            enabled_chips.insert(0,1);
            enabled_chips.insert(1,2);
            enabled_chips.insert(2,3);
            ChipBox chip(false);
            chip.chip_selection_ai(enabled_chips,player);
        }

        return true;
    }

    else
    {
        qDebug()<<"fail";
        return false;
    }
}

bool GoToOutpost::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    if(location != 11 && location != 14 && location != 18 && location != 19 &&
       location != 12 && location != 15 && location != 13 && location != 16 &&
       location != 17 && location != 20 && location != 6)
        return true;
    else
        return false;
}

bool AttendOralCommunication::main_play(int player)
{
    qDebug()<<"This is oral communication";
    if(pre_requisite_satified(player))
    {
        qDebug()<<"Success";
        quality_points[player] += 4;
        if(player == MainWindow::main_player_id)
        {
            ChipBox chip(true);
            if(ChipBox::got_integrity_chip)
            {
                integrity_chips[player] += 1;
                ChipBox::got_integrity_chip = false;
            }
            else if(ChipBox::got_craft_chip)
            {
                craft_chips[player] += 1;
                ChipBox::got_craft_chip = false;
            }
            else if(ChipBox::got_learning_chip)
            {
                learning_chips[player] += 1;
                ChipBox::got_learning_chip = false;
            }
        }

        else
        {
            QList<int> enabled_chips;
            enabled_chips.insert(0,1);
            enabled_chips.insert(1,2);
            enabled_chips.insert(2,3);
            ChipBox chip(false);
            chip.chip_selection_ai(enabled_chips,player);
        }

        return true;
    }
    else
    {
        qDebug()<<"fail";
        remove_game_card_from_hand(player);
        return false;
    }
}

bool AttendOralCommunication::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    int integrity = integrity_chips[player];
    if(location != 11 && location != 14 && location != 18 && location != 19 &&
       location != 12 && location != 15 && location != 13 && location != 16 &&
       location != 17 && location != 20 && integrity >= 4)
        return true;
    else
        return false;
}

bool PassChemsitry111::main_play(int player)
{
    qDebug()<<"This is pass chemistry";
    if(pre_requisite_satified(player))
    {
        qDebug()<<"Success";
        quality_points[player] += 5;

        return true;
    }
    else
    {
        qDebug()<<"fail";
        MainWindow window(false);
        window.relocate(2, MainWindow::players[player],
                        MainWindow::y_offsets[player]);

        return false;
    }
}

bool PassChemsitry111::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    int craft = craft_chips[player];
    if(location != 11 && location != 14 && location != 18 && location != 19 &&
       location != 12 && location != 15 && location != 13 && location != 16 &&
       location != 17 && location != 20 && craft >= 6)
        return true;
    else
        return false;
}

bool LearnLinux::main_play(int player)
{
    qDebug()<<"This is learn linux";
    if(pre_requisite_satified(player))
    {
        qDebug()<<"Success";
        quality_points[player] += 3;
        if(player == MainWindow::main_player_id)
        {
            ChipBox chip(true);
            if(ChipBox::got_integrity_chip)
            {
                integrity_chips[player] += 1;
                ChipBox::got_integrity_chip = false;
            }
            else if(ChipBox::got_craft_chip)
            {
                craft_chips[player] += 1;
                ChipBox::got_craft_chip = false;
            }
            else if(ChipBox::got_learning_chip)
            {
                learning_chips[player] += 1;
                ChipBox::got_learning_chip = false;
            }
        }

        else
        {
            QList<int> enabled_chips;
            enabled_chips.insert(0,1);
            enabled_chips.insert(1,2);
            enabled_chips.insert(2,3);
            ChipBox chip(false);
            chip.chip_selection_ai(enabled_chips,player);
        }

        return true;
    }
    else
    {
        qDebug()<<"fail";
        quality_points[player] -= 1;

        return false;
    }
}

bool LearnLinux::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    int craft = craft_chips[player];
    int integrity = integrity_chips[player];
    if(location == 11 && integrity >= 3 && craft >= 2 )
        return true;
    else
        return false;
}


bool MakeFriend::main_play(int player)
{
    qDebug()<<"This is make friend";
    if(pre_requisite_satified(player))
    {
        qDebug()<<"Success";
        quality_points[player] += 3;
        if(player == MainWindow::main_player_id)
        {
            ChipBox chip(true);
            if(ChipBox::got_integrity_chip)
            {
                integrity_chips[player] += 1;
                ChipBox::got_integrity_chip = false;
            }
            else if(ChipBox::got_craft_chip)
            {
                craft_chips[player] += 1;
                ChipBox::got_craft_chip = false;
            }
            else if(ChipBox::got_learning_chip)
            {
                learning_chips[player] += 1;
                ChipBox::got_learning_chip = false;
            }
        }

        else
        {
            QList<int> enabled_chips;
            enabled_chips.insert(0,1);
            enabled_chips.insert(1,2);
            enabled_chips.insert(2,3);
            ChipBox chip(false);
            chip.chip_selection_ai(enabled_chips,player);
        }

        return true;
    }
    else
    {
        qDebug()<<"fail";
        remove_game_card_from_hand(player);

        return false;
    }
}

bool MakeFriend::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    int integrity = integrity_chips[player];
    if((location == 12 || location == 15) && integrity >= 2)
        return true;
    else
        return false;
}

bool EnjoyNature::main_play(int player)
{
    qDebug()<<"This is enjoy nature";
    if(pre_requisite_satified(player))
    {
        qDebug()<<"Success";
        craft_chips[player] += 1;
        MainWindow window(false);
        window.relocate(20, MainWindow::players[player],
                        MainWindow::y_offsets[player]);

        return true;
    }
    else
    {
        qDebug()<<"fail";
        return false;
    }
}

bool EnjoyNature::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    if(location != 11 && location != 14 && location != 18 && location != 19 &&
       location != 12 && location != 15 && location != 13 && location != 16 &&
       location != 17 && location != 20)
        return true;
    else
        return false;
}

bool ParkInStudentParking::main_play(int player)
{
    qDebug()<<"This is parking in student parking";
    if(pre_requisite_satified(player))
    {
        qDebug()<<"Success";
        craft_chips[player] += 1;
        MainWindow window(false);
        window.relocate(20, MainWindow::players[player],
                        MainWindow::y_offsets[player]);

        return true;
    }

    else
    {
        qDebug()<<"fail";
        return false;
    }
}

bool ParkInStudentParking::pre_requisite_satified(int player)
{
    int location = MainWindow::current_postions[player];
    if(location == 2)
        return true;
    else
        return false;
}

void GamePlay::add_game_card_in_hand(int player)
{
    if(player == MainWindow::main_player_id)
    {
        randomize_deck();
        int top_of_deck = complete_card_deck.value(0);
        if(top_of_deck >= 0 && top_of_deck <= 51)
        {
             complete_card_deck.removeFirst();
             cards_in_hand.insert(0,top_of_deck);
             top_card_in_hand = 0;
             MainWindow window(false);
             window.set_icon_as_card();
        }
    }

    else if(player == MainWindow::ai_player1_id)
    {
        randomize_deck();
        int top_of_deck = complete_card_deck.value(0);
        if(top_of_deck != 0)
        {
             complete_card_deck.removeFirst();
             ai1_hand.insert(0,top_of_deck);
        }
    }

    else
    {
        randomize_deck();
        int top_of_deck = GamePlay::complete_card_deck.value(0);
        if(top_of_deck != 0)
        {
             complete_card_deck.removeFirst();
             ai2_hand.insert(0,top_of_deck);
        }
    }
}

void GamePlay::remove_game_card_from_hand(int player)
{
    if(player == MainWindow::main_player_id)
    {
        int hand = cards_in_hand.size();
        int card_to_be_removed = gen_rand_number(hand);
        if(card_to_be_removed != 0)
        {
            if(card_to_be_removed == top_card_in_hand)
            {
                discarded_card_deck.append(card_to_be_removed - 1);
                cards_in_hand.removeAt(card_to_be_removed - 1);
            }
            else
            {
                discarded_card_deck.append(card_to_be_removed);
                cards_in_hand.removeAt(card_to_be_removed);
            }
        }
        else
        {
            card_to_be_removed = 3;
            if(card_to_be_removed == top_card_in_hand)
            {
                discarded_card_deck.append(card_to_be_removed - 1);
                cards_in_hand.removeAt(card_to_be_removed - 1);

            }
            else
            {
                discarded_card_deck.append(card_to_be_removed);
                cards_in_hand.removeAt(card_to_be_removed);
            }
        }
    }

    if(player == MainWindow::ai_player1_id)
    {
        int hand = ai1_hand.size();
        int card_to_be_removed = gen_rand_number(hand);
        if(card_to_be_removed != 0)
        {
            discarded_card_deck.append(card_to_be_removed);
            ai1_hand.removeAt(card_to_be_removed);
        }
        else
        {
            discarded_card_deck.append(1);
            ai1_hand.removeAt(1);
        }
    }

    if(player == MainWindow::ai_player2_id)
    {
        int hand = ai2_hand.size();
        int card_to_be_removed = gen_rand_number(hand);
        if(card_to_be_removed != 0)
        {
            discarded_card_deck.append(card_to_be_removed);
            ai2_hand.removeAt(card_to_be_removed);
        }
        else
        {
            discarded_card_deck.append(1);
            ai2_hand.removeAt(1);
        }
    }
}
