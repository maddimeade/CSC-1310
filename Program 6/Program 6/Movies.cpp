/*
	Title:  Movies.cpp
	Author:  April R Crockett
	Date:  11/7/2017
	Purpose:  Be able to create, manage, print, save & delete a movie library
*/
#include "Movies.h"
#include "Movie.h"

Movies::Movies()
{
	moviesList = new LinkedList<Movie*>;
}

Movies::~Movies()
{
	int numMovies = getNumMovies();
	
	//delete each individual movie
	for(int x=numMovies - 1; x>=0; x--)
	{
		moviesList->deleteNode(x);
	}
}

void Movies::addMovieToList() 
{
	char tempString[100];
	int length, year, numOscars;
	double numStars;
	Text* title;
	Text* genre;
	Text* rating;
	
	//add a movie
	cin.ignore();  //remove the \n from the keyboard buffer
	cout << "\n\nMOVIE TITLE: ";
	cin.getline(tempString, 100);
	title = new Text(tempString);
	
	if(binarySearch(title->getText()) == -1)
	{
		cout << "\nMOVIE LENGTH (in minutes): ";
		cin >> length;
		cout << "\nMOVIE YEAR: ";
		cin >> year;
		cin.ignore();
		cout << "\nMOVIE GENRE: ";
		cin.getline(tempString, 100);
		genre = new Text(tempString);
		cout << "\nMOVIE RATING: ";
		cin.getline(tempString, 100);
		rating = new Text(tempString);
		cout << "\nNUMBER OF OSCARS WON: ";
		cin >> numOscars;
		cout << "\nSTAR RATING (out of 10): ";
		cin >> numStars;
	
	//create the movie
		Movie* oneMovie = new Movie(title, length, year, genre, rating, numOscars, numStars);
	
		moviesList->appendNode(oneMovie);
		
		insertionSort();
	}
	else
	{
		 cout << "\nSorry! " << title->getText() << " is already in in your movie library so it will not be added again.\n";
	}
}

void Movies::removeMovieFromList()
{
	int movieChoice;
	int numMovies;
	
	numMovies = getNumMovies();
	
	if(numMovies <= 1)
	{
	   cout << endl << "There must always be at least one movie in your library.  You can\'t";
	   cout << " remove any movies right now or you will have no movies in your library.\n";
	}
	else
	{
		cout << "\n\nChoose from the following movies to remove:\n";
		displayMovieTitles();
		cout << "\nChoose a movie to remove between 1 & " << numMovies << ":  ";
		cin >> movieChoice;
		
		while(movieChoice < 1 || movieChoice > numMovies)
		{
			cout << "\nOops!  You must enter a number between 1 & " << numMovies << ":  ";
			cin >> movieChoice;
		}

		int movieIndexToBeRemoved = movieChoice-1;
		Text* movieTitle;
		movieTitle = moviesList->getNodeValue(movieIndexToBeRemoved)->getMovieTitle();
		
		cout << "\n\nThe movie \"";
		movieTitle->displayText();
		cout << "\" has been successfully deleted.\n";	
		
		//destroy this movie
		moviesList->deleteNode(movieIndexToBeRemoved);
	}
}

void Movies::editMovieInList()
{
	int numMovies = getNumMovies();
	int movieChoice;
	
	cout << "\n\nChoose from the following movies to edit:\n";
	displayMovieTitles();
	
	cout << "\nChoose a movie to edit between 1 & " << numMovies << ":  ";
	cin >> movieChoice;
	
	while(movieChoice < 1 || movieChoice > numMovies)
	{
		cout << "\nOops!  You must enter a number between 1 & " << numMovies << ":  ";
		cin >> movieChoice;
	}
	
	Movie* oneMovie = moviesList->getNodeValue(movieChoice-1);
	
	oneMovie->editMovie();
}



void Movies::displayMovies()
{
	int numMovies = getNumMovies();
	
	if(numMovies > 0)
	{
		for(int x=0; x < (numMovies); x++)
		{
			cout << endl << right << setw(50) << "----------MOVIE " << (x+1) << "----------";
			moviesList->getNodeValue(x)->printMovieDetails(); //function is in Movie.cpp
		}
	}
	else	
		cout << "\nThere are no movies in your library yet.";
}

void Movies::displayMovieTitles()
{
	int numMovies = getNumMovies();
	Text* movieTitle;
	
	for(int x=0; x<numMovies; x++)
	{
		cout << "\nMOVIE " << (x+1) <<": ";
		movieTitle = moviesList->getNodeValue(x)->getMovieTitle();
		movieTitle->displayText();
	}
}

void Movies::readMoviesFromFile(char *filename)
{
	int numMovies = getNumMovies();
	int numMoviesReadFromFile = 0;
	ifstream inFile;
	char temp[100];
	Text* title;
	Text* genre;
	Text* rating;
	Movie* oneMovie;
	int movieLength; //length of movie in minutes
	int movieYear; //year released
	int movieOscars; //number of oscars won
	float movieNumStars; //from IMDB out of 10 stars
	
	inFile.open(filename);
	if(inFile.good())
	{
		inFile.getline(temp, 100);
		while(!inFile.eof())
		{	
			title = new Text(temp);//create a text for the movie title
			inFile >> movieLength;
			inFile >> movieYear;
			inFile.ignore(); //get rid of \n in the inFile buffer
			
			inFile.getline(temp, 100); //read in genre
			genre = new Text(temp); //create a text for genre
			inFile.getline(temp, 100); //read in rating
			rating = new Text(temp); //create a text for rating
			inFile >> movieOscars;
			inFile >> movieNumStars;
			inFile.ignore(); //get rid of \n in the inFile buffer
			
			if(binarySearch(title->getText()) == -1)
			{
				//one movie has been read from the file.  Now create a movie object
				oneMovie = new Movie(title, movieLength, movieYear, genre, rating, movieOscars, movieNumStars);
			
				//now add this movie to the library

				moviesList->appendNode(oneMovie);
				
				//confirm addition to user
				cout << endl;
				title->displayText();
				cout << " was added to the movie library!\n";
				
				insertionSort();
				numMoviesReadFromFile++;
			}
			else
			{
				 cout << "\nSorry! " << title->getText() << " is already in in your movie library so it will not be added again.\n";
			}
						
			inFile.getline(temp, 100); //read in the next movie title if there is one
		}
		
		cout << "\n\n" << numMoviesReadFromFile << " movies were read from the file and added to your movie library.\n\n";
	}
	else
	{
		cout << "\n\nSorry, I was unable to open the file.\n";
	}
}

void Movies::saveToFile(char *filename)
{
	int numMovies = getNumMovies();
	
	ofstream outFile;
	
	outFile.open(filename);
	
	for(int x=0; x<numMovies; x++)
	{
		moviesList->getNodeValue(x)->printMovieDetailsToFile(outFile); //function in Movies.cpp
	}
	outFile.close();
	
	cout << "\n\nAll movies in your library have been printed to " << filename << endl;
}

int Movies::getNumMovies() const
{
	int numMovies;
	numMovies = moviesList->getLength();
	return numMovies;
}

int Movies::binarySearch(const char* key)
{
	int mid = 0;
	int low = 0;
	int high = 0;
	   
	high = getNumMovies() - 1;

	while (high >= low) 
	{
		mid = (high + low) / 2;
		
		if (strcmp(moviesList->getNodeValue(mid)->getMovieTitle()->getText(), key) < 0) 
		{
			low = mid + 1;
		}
	 	else if (strcmp(moviesList->getNodeValue(mid)->getMovieTitle()->getText(), key) > 0) 
		{
			high = mid - 1;
		}
		else {
		return mid;
		}
	}
	return -1;
}

void Movies::insertionSort() 
{
	int i = 0;
	int j = 0;
	const char* tempstring1;
	const char* tempstring2;
	int numbersSize = getNumMovies();
	
	for (i = 1; i < numbersSize; ++i)
	{
		j = i;
		tempstring1 = moviesList->getNodeValue(j)->getMovieTitle()->getText();
		tempstring2 = moviesList->getNodeValue(j - 1)->getMovieTitle()->getText();
		
		while (j > 0 && strcmp(tempstring1, tempstring2) < 0) 
		{
			moviesList->swap(j,j - 1);
			--j;
			
			if(j != 0)
			{
				tempstring1 = moviesList->getNodeValue(j)->getMovieTitle()->getText();
				tempstring2 = moviesList->getNodeValue(j - 1)->getMovieTitle()->getText();
			}
		}
   } 
   return;
}



