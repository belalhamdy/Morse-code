#include<bits/stdc++.h>


using namespace std;
string morsealpha[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
string morsenum[10] = {"-----",".----","..---","...--","....-","....","-....","--...","---..","----."};
int finalpha ( string srch )
{
    for (int i = 0 ; i<26 ; i++)
    {
        if (morsealpha[i]== srch)
            return i ;
    }
    return 0 ;
}
int finnum ( string srch )
{
    for (int i =0 ; i<10 ; i++)
    {
        if (morsenum[i]==srch)
            return i ;
    }
    return 0 ;
}

int main()
{
    int type ;
    cout << "Please enter encrypt (1) or decode (2)\n" ;
    cin >> type ;
    if ((type !=1 && type !=2))
    {
        cout << "Invalid type\n";
        return 0 ;
    }
    string word ;
    string test , emp ;
    int index ;
    bool alpha = false ;
    cout << "Enter your word : " ;
    cin >> word ;



    if (type == 1)
    {
        for (int i = 0 ; i<word.size() ; i++)
        {
            if (isalpha(word[i]))
            {
                tolower(word[i]) ;
                cout << morsealpha[abs(word[i] - 'a')]<<" ";
            }
            else if (isalnum(word[i]))
            {
                cout << morsenum[int(word[i])];
            }
            else if (word[i] == ' ')
                cout << "\\ " ;
        }
    }
    else
    {
        for (int i = 0 ; i<word.size() ; i++)
        {
            if (word[i]!= ' ')
            {
                test += word[i] ;
            }
            else if (word[i]== '\\')
            {
                cout << " " ;
            }
            else
            {
                if (!finalpha(test))
                {
                    index = int(finnum(test)) ;
                    alpha = true ;
                }
                else
                {
                    index = int(finalpha(test)) ;
                }
                if (alpha = true)
                {
                    cout << char(index + 'a') ;
                    test = emp ;
                }
            }
        }
    }
    cin >> word;
    return 0;



}
