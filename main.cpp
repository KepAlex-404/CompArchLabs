#include <iostream>
#include <unistd.h>
#include <getopt.h>
#include <chrono>
#include <ctime>
#include <unistd.h>

using namespace std;

void help();
void getDate();
void exc(int);


int main(int argc, char *argv[]) {
    int rez = -1;
    int option_index;
    const char* short_options = "hd::e:";
    const struct option long_options[] = {
            {"help",no_argument,NULL,'h'},
            {"date",no_argument,NULL,'d'},
            {"exec",optional_argument,NULL,'e'},
            {NULL,0,NULL,0}
    };
    int h_counter = 1;
    int d_counter = 1;
    int e_counter = 1;


    while ((rez = getopt_long(argc, argv, short_options, long_options, &option_index))  != -1) {
        switch(rez){
            case 'h': {
                if (h_counter < 1){
                    goto exitH;
                }
                h_counter--;
                help();
                exitH: break;
            }
            case 'd': {
                if (d_counter < 1){
                    goto exitV;
                }
                d_counter--;
                getDate();

                exitV: break;
            }

            case 'e': {
                if (e_counter < 1){
                    goto exitY;
                }
                e_counter--;
                if (optarg!=NULL)
                    exc(atoi(optarg));
                else
                    exc(200);

                exitY: break;
            }

            case '?': default: {
                printf("Unknown option\n");
                break;
            }
        }
    }
}

void help()
{
//    выводит возможный функционал этой очень полезной программы )

    printf("Введите -h (--help) для получения подсказки\n"
           "введите -d (--date) для получения текущего времени\n"
           "введите -e (--exec) для выполнения 'очень' долгой задачи\n");
}

void getDate()
{
//    выводит дату
    auto end = std::chrono::system_clock::now();
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    std::cout << "Current time " << std::ctime(&end_time) << endl;
}

void exc(int number){
//  симулятор студента - делает вид что работает. \
//  Параметр - то сколько он на это потратит времени, если параметра нет то 200 миллисекунд
    printf("Perform long execution for %d milliseconds....\n", number);

    usleep(number);

    printf("... and this is the end... \n");
}