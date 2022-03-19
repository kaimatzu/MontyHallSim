#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

struct resHolder {
    int choice;
    bool correct;
    bool switched;
};

bool monty(int choice, bool &switched){
    int correct = 1 + rand() % 3;
    int monty = (rand() % 2 == 0) ? 1 : -1;
    bool sw = (rand() % 2 == 0) ? true : false;
    
    if(correct == 3 && monty == 1){
        if(choice == 2 && sw == true)
            {switched = true; return true;}
        else if(choice == 3 && sw == false)
            {switched = false; return true;}
        else if(choice == 2 && sw == false)
            {switched = false; return false;}
        else if(choice == 3 && sw == true)
            {switched = true; return false;}
    }
    else if(correct == 3 && monty == -1){
        if(choice == 1 && sw == true)
            {switched = true; return true;}
        else if(choice == 3 && sw == false)
            {switched = false; return true;}
        else if(choice == 1 && sw == false)
            {switched = false; return false;}
        else if(choice == 3 && sw == true)
            {switched = true; return false;}
    }      
    else if(correct == 2 && monty == 1){
        if(choice == 1 && sw == true)
            {switched = true; return true;}
        else if(choice == 2 && sw == false)
            {switched = false; return true;}
        else if(choice == 1 && sw == false)
            {switched = false; return false;}
        else if(choice == 2 && sw == true)
            {switched = true; return false;}
    }      
    else if(correct == 2 && monty == -1){
        if(choice == 3 && sw == true)
            {switched = true; return true;}
        else if(choice == 2 && sw == false)
            {switched = false; return true;}
        else if(choice == 3 && sw == false)
            {switched = false; return false;}
        else if(choice == 2 && sw == true)
            {switched = true; return false;}
    }     
    else if(correct == 1 && monty == 1){
        if(choice == 3 && sw == true)
            {switched = true; return true;}
        else if(choice == 1 && sw == false)
            {switched = false; return true;}
        else if(choice == 3 && sw == false)
            {switched = false; return false;}
        else if(choice == 1 && sw == true)
            {switched = true; return false;}
    }     
    else if(correct == 1 && monty == -1){
        if(choice == 2 && sw == true)
            {switched = true; return true;}
        else if(choice == 1 && sw == false)
            {switched = false; return true;}
        else if(choice == 2 && sw == false)
            {switched = false; return false;}
        else if(choice == 1 && sw == true)
            {switched = true; return false;}
    }     
    return NULL;
}

int main(){

    srand(time(NULL));
    resHolder arr[(unsigned long long)1e5];
    int switched_amt = 0;
        
    for(int i = 0; i < 1e5; i++){
        bool *switched = &arr[i].switched;
        arr[i].choice = 1 + rand() % 3;
        arr[i].correct = monty(arr[i].choice, *switched);
    }


    int switched_correct_ones = 0, switched_correct_twos = 0, switched_correct_threes = 0;
    int unswitched_correct_ones = 0, unswitched_correct_twos = 0, unswitched_correct_threes = 0;
    int switched_incorrect_ones = 0, switched_incorrect_twos = 0, switched_incorrect_threes = 0;
    int unswitched_incorrect_ones = 0, unswitched_incorrect_twos = 0, unswitched_incorrect_threes = 0;
    for(int i = 0; i < 1e5; i++){
        //correct
        if(arr[i].choice == 1 && arr[i].correct == true && arr[i].switched == true){
            switched_correct_ones++;
        }
        else if(arr[i].choice == 2 && arr[i].correct == true && arr[i].switched == true){
            switched_correct_twos++;
        }
        else if(arr[i].choice == 3 && arr[i].correct == true && arr[i].switched == true){
            switched_correct_threes++;
        }
        else if(arr[i].choice == 1 && arr[i].correct == true && arr[i].switched == false){
            unswitched_correct_ones++;
        }
        else if(arr[i].choice == 2 && arr[i].correct == true && arr[i].switched == false){
            unswitched_correct_twos++;
        }
        else if(arr[i].choice == 3 && arr[i].correct == true && arr[i].switched == false){
            unswitched_correct_threes++;
        }
        //incorrect
        else if(arr[i].choice == 1 && arr[i].correct == false && arr[i].switched == true){
            switched_incorrect_ones++;
        }
        else if(arr[i].choice == 2 && arr[i].correct == false && arr[i].switched == true){
            switched_incorrect_twos++;
        }
        else if(arr[i].choice == 3 && arr[i].correct == false && arr[i].switched == true){
            switched_incorrect_threes++;
        }
        else if(arr[i].choice == 1 && arr[i].correct == false && arr[i].switched == false){
            unswitched_incorrect_ones++;
        }
        else if(arr[i].choice == 2 && arr[i].correct == false && arr[i].switched == false){
            unswitched_incorrect_twos++;
        }
        else if(arr[i].choice == 3 && arr[i].correct == false && arr[i].switched == false){
            unswitched_incorrect_threes++;
        }
    }
    cout << "Switched correct ones: " << switched_correct_ones << endl;

    cout << "Switched correct ones: " << switched_correct_twos << endl;

    cout << "Switched correct ones: " << switched_correct_threes << endl;
    
    cout << "Unswitched correct ones: " << unswitched_correct_ones << endl;

    cout << "Unswitched correct ones: " << unswitched_correct_twos << endl;

    cout << "Unswitched correct ones: " << unswitched_correct_threes << endl;

    cout << "Switched incorrect ones: " << switched_incorrect_ones << endl;

    cout << "Switched incorrect ones: " << switched_incorrect_twos << endl;

    cout << "Switched incorrect ones: " << switched_incorrect_threes << endl;
    
    cout << "Unswitched incorrect ones: " << unswitched_incorrect_ones << endl;

    cout << "Unswitched incorrect ones: " << unswitched_incorrect_twos << endl;

    cout << "Unswitched incorrect ones: " << unswitched_incorrect_threes << endl;

    cout << "Total: " << switched_correct_ones + switched_correct_twos + switched_correct_threes + switched_incorrect_ones + switched_incorrect_twos + switched_incorrect_threes + unswitched_correct_ones + unswitched_correct_twos + unswitched_correct_threes + unswitched_incorrect_ones + unswitched_incorrect_twos + unswitched_incorrect_threes << endl;

    float percentage = (switched_correct_ones + switched_correct_twos + switched_correct_threes) / 1e5;
    cout << "No. of success by switching: " << setprecision(4) << percentage << endl;

}
//switched + correct, switched + uncorrect, unswitched + correct, unswitched + uncorrect
