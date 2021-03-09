#include<iostream>
#include<random>
#include<ctime>
 
const int guesses = 7;
 
int pickNum(int min,int max)
{
    static std::mt19937 mersenne(static_cast<unsigned int>(time(0)));
 
    static const double fraction=1.0/(static_cast<double>(mersenne.max())+1.0);
 
    return min+(max-min+1)* (mersenne()*fraction);
}
 
 
void playHilo(int x,int guesses)
{
    std::cout<<"Guess My Number!\n\n";
    std::cout<<"I'm thinking of a number...to guess, enter a number between 1 and 10: \n";
    int guess;
    for(int i=1;i<=guesses;++i)
    {
        std::cin>>guess;
        if (guess < x && i < guesses)
            std::cout<<guess<<" is too low. You have "<<guesses-i<<" tries left \n";
        if(guess > x && i < guesses)
            std::cout<<guess<<" is too high. You have "<<guesses-i<<" tries left \n";
        if(guess == x)
        {
            std::cout<<" You won! The number was "<<x<<"\n";
            break;
        }
 
        if (i==guesses && guess != x)
            std::cout<<"Sorry you lose! The number was "<<x<<"\n";
    }
}
 
void playAgain()
{
    char answer;
    int x = pickNum(1,10);
    while(true)
    {
        std::cout<<"Play again? (y/n)";
        std::cin>>answer;
        std::cin.ignore(32767,'\n');
        if(answer == 'y')
            playHilo(x,guesses);
 
        else if(answer == 'n')
            std::cout<<"Thanks for playing. \n";
            exit(0);
    }
}
int main()
{
    int x = pickNum(1,10);
    playHilo(x,guesses);
    playAgain();
return 0;
}