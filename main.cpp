#include <iostream>
#include <graphics.h>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <fstream>


#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wconversion"
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wwritable-strings"

using namespace std;

void menu();

void chooseLevelToPlay();

void initializePoints();

void beginner();

void sort(int *, int *, int *, int);

void getRandedxy(int *, int *, int);

void printNumber(int *, int *, int *, int);

void backToMenuButton();

void playAgainButton();

void fillAllRec();

void clearAllRec();

void medium();

void hard();

void initializeScoreFiles();

int getScore(char *);

void displayScore(int); // show score after play

void chooseLevelToHighscore();

void showBeginnerHighscore();

void showMediumHighscore();

void showHardHighscore();

void drawHighscore(int *);

void drawGameover();

int recx[8];
int recy[5];

int startTime;
int endTime;
int eachClick;
int howMuchRound;

int score;


#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic pop

int main() {

    srand(time(NULL));

    DWORD sw = GetSystemMetrics(SM_CXSCREEN);
    DWORD sh = GetSystemMetrics(SM_CYSCREEN);
    initwindow(sw + 5, sh + 5, "", -5, -5);

    initializePoints();
    initializeScoreFiles();

    eachClick = 0;
    howMuchRound = 0;

    std::time_t result = std::time(NULL);
    startTime = result;

    menu();

    getch();
    closegraph();

}

#pragma clang diagnostic pop

void menu() {

    settextstyle(1, 0, 36);

    outtextxy(540, 200, "Ayumu Game");

    int xText = 100;

    for (int j = 0; j < 500; ++j) {
        outtextxy(xText < 550 ? ++xText : xText, 350, "New Game");
        outtextxy(xText, 400, "High Score");
    }
    delay(500);
    rectangle(530, 345, 750, 380);
    rectangle(530, 395, 750, 430);

    POINT p1;
    while (true) {

        GetCursorPos(&p1);
        if (GetAsyncKeyState(VK_LBUTTON)) {
            if (p1.x > 550 && p1.x < 750) {

                if (p1.y > 345 && p1.y < 375) {
                    fillAllRec();
                    clearAllRec();
                    cleardevice();
                    chooseLevelToPlay();
                    break;

                }
                if (p1.y > 400 && p1.y < 430) {
                    chooseLevelToHighscore();
                    break;
                }
                if (p1.y > 450 && p1.y < 480) {
                }
                if (p1.y > 500 && p1.y < 530) {
                }
            }
        }
    }

}

void chooseLevelToPlay(){

    backToMenuButton();

    setcolor(WHITE);
    setfillstyle(1, BLACK);
    rectangle(530, 347, 750, 382);
    rectangle(530, 397, 750, 432);
    rectangle(530, 447, 750, 482);

    setcolor(WHITE);
    setbkcolor(BLACK);
    outtextxy(550, 350, "Easy");
    outtextxy(550, 400, "Medium");
    outtextxy(550, 450, "Hard");

    POINT pt;

    while (true) {
        GetCursorPos(&pt);
        if (GetAsyncKeyState(VK_LBUTTON)) {
            if(pt.x>530 && pt.x <750){
                if(pt.y > 347 && pt.y<382){
                    fillAllRec();
                    clearAllRec();
                    beginner();
                    break;
                }
                if(pt.y>397 && pt.y<432){
                    fillAllRec();
                    clearAllRec();
                    medium();break;
                }
                if(pt.y>447 && pt.y<482){
                    fillAllRec();
                    clearAllRec();
                    hard();
                }
            }
            if (pt.x >= 70 && pt.x <= 175) {
                if (pt.y >= 50 && pt.y <= 100) {
                    cleardevice();
                    menu();
                    break;
                }
            }
        }
    }
}

void chooseLevelToHighscore(){

    fillAllRec();
    clearAllRec();
    cleardevice();

    backToMenuButton();

    setcolor(WHITE);
    setfillstyle(1, BLACK);
    rectangle(530, 347, 750, 382);
    rectangle(530, 397, 750, 432);
    rectangle(530, 447, 750, 482);

    setcolor(WHITE);
    setbkcolor(BLACK);
    outtextxy(550, 350, "Easy");
    outtextxy(550, 400, "Medium");
    outtextxy(550, 450, "Hard");

    POINT pt;

    while (true) {
        GetCursorPos(&pt);
        if (GetAsyncKeyState(VK_LBUTTON)) {
            if(pt.x>530 && pt.x <750){
                if(pt.y > 347 && pt.y<382){
                    fillAllRec();
                    clearAllRec();
                    showBeginnerHighscore();
                    break;
                }
                if(pt.y>397 && pt.y<432){
                    fillAllRec();
                    clearAllRec();
                    showMediumHighscore();
                    break;
                }
                if(pt.y>447 && pt.y<482){
                    fillAllRec();
                    clearAllRec();
                    showHardHighscore();
                }
            }
            if (pt.x >= 70 && pt.x <= 175) {
                if (pt.y >= 50 && pt.y <= 100) {
                    cleardevice();
                    menu();
                    break;
                }
            }
        }
    }
}

void initializePoints() {

    int startx = 150;
    int starty = 170;

    int xfactor = 115;
    int yfactor = 115;

    for (int i = 0; i < 8; i++) {
        recx[i] = startx;
        startx += xfactor;
    }

    for (int i = 0; i < 5; i++) {
        recy[i] = starty;
        starty += yfactor;
    }
}


#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"

void beginner() {

    backToMenuButton();
    playAgainButton();

    fillAllRec();

    int randedx[5];
    int randedy[5];
    int number[5];

    getRandedxy(randedx, randedy, 5);

    printNumber(randedx, randedy, number, 5);

    sort(randedx, randedy, number, 5);

    POINT pt;

    int x = randedx[0];
    int y = randedy[0];

    while (true) {
        GetCursorPos(&pt);
        if (GetAsyncKeyState(VK_LBUTTON)) {
            // Handle back button
            if (pt.x >= 70 && pt.x <= 175) {
                if (pt.y >= 50 && pt.y <= 100) {
                    howMuchRound = 0;
                    eachClick = 0;

                    cleardevice();


                    menu();
                    break;
                }
            }
            if (pt.x >= x && pt.x <= x + 100) {
                if (pt.y >= y && pt.y <= y + 100) {
                    //cout << "truly clicked" << endl;

                    if (eachClick == 0) {
                        for (int j = 1; j < 5; j++) {
                            setcolor(WHITE);
                            setfillstyle(1, WHITE);
                            rectangle(randedx[j], randedy[j], randedx[j] + 100, randedy[j] + 100);
                            floodfill(randedx[j] + 5, randedy[j] + 5, WHITE);
                        }
                    }

                    setcolor(COLOR(1, 1, 1));
                    setfillstyle(1, BLACK);
                    rectangle(randedx[eachClick], randedy[eachClick], randedx[eachClick] + 100,
                              randedy[eachClick] + 100);
                    floodfill(randedx[eachClick] + 5, randedy[eachClick] + 5, COLOR(1, 1, 1));

                    eachClick += 1;
                    x = randedx[eachClick];
                    y = randedy[eachClick];

                    if (eachClick == 5) {
                        howMuchRound++;
                        eachClick = 0;
                        fillAllRec();
                        clearAllRec();
                        if (howMuchRound == 3) {

                            std::time_t result = std::time(NULL);
                            endTime = result;
                            howMuchRound = 0;
                            eachClick = 0;

                            displayScore(1);


                        } else {
                            beginner();
                        }
                    }


                }
            } else {
                fillAllRec();
                clearAllRec();
                drawGameover();

                cout << "game over" << endl;

            }

            if (pt.x >= 1200 && pt.x <= 1300) {
                if (pt.y >= 690 && pt.y <= 780) {

                    fillAllRec();
                    clearAllRec();

                    howMuchRound = 0;
                    eachClick = 0;

                    std::time_t result = std::time(NULL);
                    startTime = result;

                    beginner();
                }
            }
        }


    }

}

void medium() {

    fillAllRec();
    clearAllRec();
    backToMenuButton();
    playAgainButton();

    int randedx[5];
    int randedy[5];
    int number[5];

    getRandedxy(randedx, randedy, 5);

    printNumber(randedx, randedy, number, 5);

    sort(randedx, randedy, number, 5);

    int x = randedx[0];
    int y = randedy[0];

    POINT pt;

    while (true) {
        GetCursorPos(&pt);
        if (GetAsyncKeyState(VK_LBUTTON)) {

            if (pt.x >= 70 && pt.x <= 175) {
                if (pt.y >= 50 && pt.y <= 100) {
                    howMuchRound = 0;
                    eachClick = 0;

                    cleardevice();


                    menu();
                    break;
                }
            }

            // Handle play again button
            if (pt.x >= 1200 && pt.x <= 1300) {
                if (pt.y >= 690 && pt.y <= 780) {
                    fillAllRec();
                    clearAllRec();

                    howMuchRound = 0;
                    eachClick = 0;

                    std::time_t result = std::time(NULL);
                    startTime = result;

                    medium();
                }
            }

            if (pt.x >= x && pt.x <= x + 100) {
                if (pt.y >= y && pt.y <= y + 100) {
                    //cout << "truly clicked" << endl;

                    if (eachClick == 0) {
                        fillAllRec();
                    }

                    setcolor(COLOR(1, 1, 1));
                    setfillstyle(1, BLACK);
                    rectangle(randedx[eachClick], randedy[eachClick], randedx[eachClick] + 100,
                              randedy[eachClick] + 100);
                    floodfill(randedx[eachClick] + 5, randedy[eachClick] + 5, COLOR(1, 1, 1));

                    eachClick += 1;
                    x = randedx[eachClick];
                    y = randedy[eachClick];

                    // Finish one Round


                    if (eachClick == 5) {
                        howMuchRound++;
                        eachClick = 0;
                        fillAllRec();
                        clearAllRec();
                        if (howMuchRound == 3) {

                            std::time_t result = std::time(NULL);
                            endTime = result;
                            howMuchRound = 0;
                            eachClick = 0;

                            displayScore(2);


                        } else {
                            medium();
                        }
                    }


                }
            } else {


                fillAllRec();
                clearAllRec();
                drawGameover();

                cout << "game over" << endl;


            }
        }

    }


}

void hard() {

    fillAllRec();
    clearAllRec();
    backToMenuButton();
    playAgainButton();

    int randedx[9];
    int randedy[9];
    int number[9];

    getRandedxy(randedx, randedy, 9);

    printNumber(randedx, randedy, number, 9);

    sort(randedx, randedy, number, 9);

    int x = randedx[0];
    int y = randedy[0];

    POINT pt;

    while (true) {
        GetCursorPos(&pt);
        if (GetAsyncKeyState(VK_LBUTTON)) {

            if (pt.x >= 70 && pt.x <= 175) {
                if (pt.y >= 50 && pt.y <= 100) {
                    howMuchRound = 0;
                    eachClick = 0;

                    cleardevice();


                    menu();
                    break;
                }
            }
            if (pt.x >= x && pt.x <= x + 100) {
                if (pt.y >= y && pt.y <= y + 100) {
                    //cout << "truly clicked" << endl;

                    if (eachClick == 0) {
                        for (int j = 1; j < 9; j++) {
                            setcolor(WHITE);
                            setfillstyle(1, WHITE);
                            rectangle(randedx[j], randedy[j], randedx[j] + 100, randedy[j] + 100);
                            floodfill(randedx[j] + 5, randedy[j] + 5, WHITE);
                        }
                    }

                    setcolor(COLOR(1, 1, 1));
                    setfillstyle(1, BLACK);
                    rectangle(randedx[eachClick], randedy[eachClick], randedx[eachClick] + 100,
                              randedy[eachClick] + 100);
                    floodfill(randedx[eachClick] + 5, randedy[eachClick] + 5, COLOR(1, 1, 1));

                    eachClick += 1;
                    x = randedx[eachClick];
                    y = randedy[eachClick];

                    if (eachClick == 9) {
                        howMuchRound++;
                        eachClick = 0;
                        fillAllRec();
                        clearAllRec();
                        if (howMuchRound == 3) {

                            std::time_t result = std::time(NULL);
                            endTime = result;
                            howMuchRound = 0;
                            eachClick = 0;

                            displayScore(3);


                        } else {
                            hard();
                        }
                    }


                }
            } else {
                fillAllRec();
                clearAllRec();
                drawGameover();

                cout << "game over" << endl;

            }

            if (pt.x >= 1200 && pt.x <= 1300) {
                if (pt.y >= 690 && pt.y <= 780) {

                    fillAllRec();
                    clearAllRec();

                    howMuchRound = 0;
                    eachClick = 0;

                    std::time_t result = std::time(NULL);
                    startTime = result;

                    hard();
                }
            }
        }


    }

}

void sort(int recx[], int recy[], int num[], int n) {

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - 1; j++) {
            if (num[j] > num[j + 1]) {
                int temp1 = num[j];
                num[j] = num[j + 1];
                num[j + 1] = temp1;

                int temp2 = recx[j];
                recx[j] = recx[j + 1];
                recx[j + 1] = temp2;

                int temp3 = recy[j];
                recy[j] = recy[j + 1];
                recy[j + 1] = temp3;
            }
        }
    }
}

void fillAllRec() {

    setcolor(WHITE);
    setfillstyle(1, WHITE);
    rectangle(recx[0], recy[0], recx[0]+920, recy[0]+600);
    floodfill(recx[0]+5, recy[0]+5, WHITE);

    setcolor(BLACK);
    setfillstyle(1, BLACK);
    rectangle(recx[0], recy[0], recx[0]+920, recy[0]+600);
    floodfill(recx[0]+5, recy[0]+5, BLACK);

    setcolor(WHITE);
    setfillstyle(1, WHITE);
    for (int k = 0; k < 5; k++) {
        for (int j = 0; j < 8; j++) {
            int height = 100;

            rectangle(recx[j], recy[k], recx[j] + height, recy[k] + height);
            floodfill(recx[j] + 2, recy[k] + 2, WHITE);
        }
    }

}

void clearAllRec() {

    for (int k = 0; k < 5; k++) {
        for (int j = 0; j < 8; j++) {
            int height = 100;

            setcolor(BLACK);
            setbkcolor(BLACK);
            setfillstyle(1, BLACK);
            rectangle(recx[j], recy[k], recx[j] + height, recy[k] + height);
            floodfill(recx[j] + 2, recy[k] + 2, BLACK);
        }
    }

}

void backToMenuButton() {

    setcolor(WHITE);
    setfillstyle(1, WHITE);
    rectangle(75, 50, 175, 100);
    floodfill(80, 55, WHITE);

    int tri[8] = {75, 50, 75, 100, 50, 75, 75, 50};
    drawpoly(4, tri);
    floodfill(55, 75, WHITE);

    setcolor(BLACK);
    setbkcolor(WHITE);
    settextstyle(DEFAULT_FONT, 0, 15);
    outtextxy(80, 60, "Back");

}

void playAgainButton() {

    setcolor(WHITE);
    circle(1250, 750, 50);

}

void getRandedxy(int randedx[], int randedy[], int n) {

    int minx = 0;
    int maxx = 7;
    int miny = 0;
    int maxy = 4;

    for (int i = 0; i < n; i++) {
        bool boolean = true;

        while (boolean) {
            bool catched = false;

            int randx = (minx + (rand() % (maxx - minx + 1)));
            int randy = (miny + (rand() % (maxy - miny + 1)));

            for (int j = 0; j < n; ++j) {
                if (randedx[j] == recx[randx] && randedy[j] == recy[randy]) {
                    catched = true;
                    break;
                }

            }

            if (catched) {
                continue;
            } else {
                boolean = false;
            }

            randedx[i] = recx[randx];
            randedy[i] = recy[randy];

            setcolor(BLACK);
            setfillstyle(1, BLACK);
            rectangle(recx[randx], recy[randy], recx[randx] + 100, recy[randy] + 100);
            floodfill(recx[randx] + 5, recy[randy] + 5, BLACK);
        }


    }

}

void printNumber(int randedx[], int randedy[], int number[], int n) {
    for (int i = 0; i < n; i++) {
        bool boolean = true;

        while (boolean) {
            bool catched = false;

            int num = (1 + (rand() % (9)));

            for (int i = 0; i < n; i++) {
                if (number[i] == num) {
                    catched = true;
                    break;
                }
            }

            if (catched) {
                continue;
            } else {
                number[i] = num;
                boolean = false;
            }

            char ch[10];
            itoa(num, ch, 10);


            setcolor(COLOR(244, 244, 244));
            setbkcolor(BLACK);
            settextstyle(DEFAULT_FONT, 0, 64);
            outtextxy(randedx[i] + 25, randedy[i] + 10, ch);
        }
    }
}

void initializeScoreFiles() {

    fstream begginer("beginner score.txt");
    if (begginer.fail()) {
        ofstream outputFile("beginner score.txt");
        for (int i = 0; i < 10; ++i) {
            outputFile << 1000000 << endl;
        }
        outputFile.close();
    }

    fstream medium("medium score.txt");
    if (medium.fail()) {
        ofstream outputFile("medium score.txt");
        for (int i = 0; i < 10; ++i) {
            outputFile << 1000000 << endl;
        }
        outputFile.close();
    }

    fstream hard("hard score.txt");
    if (hard.fail()) {
        ofstream outputFile("hard score.txt");
        for (int i = 0; i < 10; ++i) {
            outputFile << 1000000 << endl;
        }
        outputFile.close();
    }
}

void displayScore(int level) {

    backToMenuButton();
    playAgainButton();
    score = endTime - startTime;

    int where;

    if (level == 1) {
        where = getScore("beginner score.txt");
    } else if (level == 2) {
        where = getScore("medium score.txt");
    } else if (level == 3) {
        where = getScore("hard score.txt");
    }

    setcolor(WHITE);
    setfillstyle(1, WHITE);
    rectangle(150, 170, 1200, 720);
    floodfill(155, 175, WHITE);

    setcolor(BLACK);
    setfillstyle(1, BLACK);
    rectangle(150, 170, 1200, 720);
    floodfill(155, 175, BLACK);

    char ch[10];
    itoa(score, ch, 10);

    setcolor(WHITE);
    setbkcolor(BLACK);
    settextstyle(2, 0, 10);

    outtextxy(400, 200, "Your score");
    outtextxy(400, 260, "Your Rank");
    outtextxy(800, 200, ch);

    if(where > 10 || where < 1){
        outtextxy(800, 260, "Not Ranked");
    }else {
        char c[10];
        itoa(where, c, 10);
        outtextxy(800, 260, c);
    }

    POINT pt;
    while (true) {
        GetCursorPos(&pt);
        if (GetAsyncKeyState(VK_LBUTTON)) {
            // Handle back button
            if (pt.x >= 70 && pt.x <= 175) {
                if (pt.y >= 50 && pt.y <= 100) {
                    howMuchRound = 0;
                    eachClick = 0;

                    cleardevice();


                    menu();
                    break;
                }
            }

            if (pt.x >= 1200 && pt.x <= 1300) {
                if (pt.y >= 690 && pt.y <= 780) {

                    fillAllRec();
                    clearAllRec();

                    howMuchRound = 0;
                    eachClick = 0;

                    std::time_t result = std::time(NULL);
                    startTime = result;

                    if(level == 1){
                        beginner();
                    }else if(level ==2){
                        medium();
                    }else if(level == 3){
                        hard();
                    }
                }
            }
        }
    }


}

int getScore(char file[]) {
    int scores[10];
    ifstream inFile(file);
    for (int i = 0; i < 10; i++) {
        inFile >> scores[i];
    }

    int where;
    int newScores[10];
    bool stored = false;
    for (int k = 0; k < 10; ++k) {
        if (score < scores[k] && !stored) {
            where = k;
            newScores[k] = score;
            newScores[++k] = scores[k - 1];
            stored = true;
        } else {
            if (stored) {
                newScores[k] = scores[k - 1];
            } else {
                newScores[k] = scores[k];
            }
        }
    }
    inFile.close();

    ofstream outFile(file);
    for (int l = 0; l < 10; ++l) {
        outFile << newScores[l] << endl;
    }

    outFile.close();

    return (where + 1);
}

void drawHighscore(int scores[]) {

    cleardevice();
    backToMenuButton();
    int x = 350;
    int y = 200;

    char rank[10];
    char score[10];
    for (int i = 0; i < 10; ++i) {
        itoa((i + 1), rank, 10);

        setcolor(WHITE);
        setfillstyle(1, WHITE);
        setbkcolor(BLACK);
        settextstyle(2, 0, 10);
        outtextxy(x, y += 50, rank);
    }
    y=200;
    for (int j = 0; j < 10; ++j) {
        if(scores[j] == 1000000){
            settextstyle(2, 0, 10);
            outtextxy(x + 70, y += 50, "no score! play to score!");
        }else {
            itoa(scores[j], score, 10);

            settextstyle(2, 0, 10);
            outtextxy(x + 70, y += 50, score);
        }
    }

    POINT pt;
    while (true) {
        GetCursorPos(&pt);
        if (GetAsyncKeyState(VK_LBUTTON)) {
            // Handle back button
            if (pt.x >= 70 && pt.x <= 175) {
                if (pt.y >= 50 && pt.y <= 100) {
                    howMuchRound = 0;
                    eachClick = 0;

                    cleardevice();


                    chooseLevelToHighscore();
                    break;
                }
            }
        }
    }

}

void showBeginnerHighscore() {
    int scores[10];
    ifstream inFile("beginner score.txt");

    for (int i = 0; i < 10; i++) {
        inFile >> scores[i];
    }

    drawHighscore(scores);
}

void showMediumHighscore() {
    int scores[10];
    ifstream inFile("medium score.txt");

    for (int i = 0; i < 10; i++) {
        inFile >> scores[i];
    }

    drawHighscore(scores);
}

void showHardHighscore() {
    int scores[10];
    ifstream inFile("hard score.txt");

    for (int i = 0; i < 10; i++) {
        inFile >> scores[i];
    }

    drawHighscore(scores);
}

void drawGameover(){
    setcolor(WHITE);
    settextstyle(2, 0, 10);
    setfillstyle(1, WHITE);
    setbkcolor(BLACK);
    outtextxy(550, 300, "Game Over!");
    outtextxy(400, 350, "Press circle to start again");
}