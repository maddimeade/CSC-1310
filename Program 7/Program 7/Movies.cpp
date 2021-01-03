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
			
				//one movie has been read from the file.  Now create a movie object
				oneMovie = new Movie(title, movieLength, movieYear, genre, rating, movieOscars, movieNumStars);
			
				//now add this movie to the library

				moviesList->appendNode(oneMovie);
				
				//confirm addition to user
				cout << endl;
				title->displayText();
				cout << " was added to the movie library!\n";
				
				numMoviesReadFromFile++;
						
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

int Movies::linearSearch(const char* key) 
{ 
	int pos = 0;
	int size = getNumMovies() - 1;
   
	for (pos = 0; pos <= size; pos++) 
	{   
		if(strcmp(moviesList->getNodeValue(pos)->getMovieTitle()->getText(), key) == 0)
		{
			return pos;
		}
	}
   return -1;
}

void Movies::bubbleSort()
{
	int i = 0;
	int size = getNumMovies();
	const char* tempstring1;
	const char* tempstring2;
	
	for(size - 1; size > 0; size--)
	{
		for(i=1; i < size; i++)
		{
			const char* tempstring1 = moviesList->getNodeValue(i)->getMovieTitle()->getText();
			const char* tempstring2 = moviesList->getNodeValue(i - 1)->getMovieTitle()->getText();
			if (strcmp(tempstring1, tempstring2) > 0) 
			{
				moviesList->swap(i, i-1);
			}
		}
	}
}

void Movies::insertionSortDescending() 
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
		
		while (j > 0 && strcmp(tempstring1, tempstring2) > 0) 
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

void Movies::selectionSort()
{
	int size = getNumMovies();
	int minIndex;
	const char* tempstring1;
	const char* tempstring2;
	
	for(int i = 0; i < (size-1); i++)
	{
		minIndex = i;
		tempstring1 = moviesList->getNodeValue(i)->getMovieTitle()->getText();
		
		for(int j = i+1; j<size; j++)
		{
			tempstring1 = moviesList->getNodeValue(i)->getMovieTitle()->getText();
			tempstring2 = moviesList->getNodeValue(j)->getMovieTitle()->getText();
			if(strcmp(tempstring2, tempstring1) < 0) 
			{
				tempstring1 = moviesList->getNodeValue(j)->getMovieTitle()->getText();
				minIndex = j;
			}
		}
		moviesList->swap(i, minIndex);
	}
}

void Movies::quickSort(int low, int high) 
{
	int pivot_location = 0;

	/* Base case: If there are 1 or zero elements to sort,
	partition is already sorted */
	if (low >= high) {
		return;
	}

	/* Partition the data within the array. Value pivot_location returned
	from partitioning is location of last element in low partition. */
	pivot_location = partition(low, high);

	/* Recursively sort low partition (low to pivot_location) and
	high partition (pivot_location + 1 to high) */
	quickSort(low, pivot_location);
	quickSort(pivot_location + 1, high);
}

int Movies::partition(int low, int high) 
{
   int midpoint;
   const char* pivot;
   bool done = false;
   
   midpoint = low + (high - low) / 2;
   pivot = moviesList->getNodeValue(midpoint)->getMovieTitle()->getText();
   
   int l = low;
   int h = high;
   
   while (!done) {
      
      /* Increment l while arr[l] < pivot */
      while (strcmp(moviesList->getNodeValue(l)->getMovieTitle()->getText(), pivot) < 0) {
         ++l;
      }
      
      /* Decrement h while pivot < arr[h] */
      while (strcmp(pivot, moviesList->getNodeValue(h)->getMovieTitle()->getText()) < 0) {
         --h;
      }
      
      /* If there are zero or one elements remaining,
       all numbers are partitioned. Return h */
      if (l >= h) {
         done = true;
      }
      else {
 
         moviesList->swap(l, h);
         
         ++l;
         --h;
      }
   }
   
   return h;
}

void Movies::mergeSort(int i, int k) 
{
   int j = 0;
   
   if (i < k) {
      j = (i + k) / 2;  // Find the midpoint in the partition
      
      // Recursively sort left and right partitions
      mergeSort(i, j);
      mergeSort(j + 1, k);
      
      // Merge left and right partition in sorted order
      merge(i, j, k);
   }
}

void Movies::merge(int i, int j, int k) 
{
   int mergedSize = k - i + 1;             
   int mergePos = 0;                          
   int leftPos = 0;                         
   int rightPos = 0; 
   LinkedList<Movie*> *list = new LinkedList<Movie*>; 
   const char* tempstring1;
   const char* tempstring2;
                                             
  
   leftPos = i;
   rightPos = j + 1;   
   

	while (leftPos <= j && rightPos <= k) 
	{
		tempstring1 = moviesList->getNodeValue(leftPos)->getMovieTitle()->getText();
		tempstring2 = moviesList->getNodeValue(rightPos)->getMovieTitle()->getText();
		if (strcmp(tempstring1, tempstring2) < 0)
		{
			list->appendNode(moviesList->getNodeValue(leftPos));
			++leftPos;
		}
		else 
		{
			list->appendNode(moviesList->getNodeValue(rightPos));
			++rightPos;
		}
		++mergePos;
		}
   
   // If left partition is not empty, add remaining elements to merged numbers
	while (leftPos <= j) 
	{
		list->appendNode(moviesList->getNodeValue(leftPos));
		++leftPos;
		++mergePos;
	}
   
   // If right partition is not empty, add remaining elements to merged numbers
	while (rightPos <= k) {
		list->appendNode(moviesList->getNodeValue(rightPos));
		++rightPos;
		++mergePos;
	}
   
	for (mergePos = 0; mergePos < mergedSize; ++mergePos) 
	{
       moviesList->deleteNode(i+mergePos);
       
       moviesList->insertNode(list->getNodeValue(mergePos), mergePos+i);
	}
	
}

void Movies::algorithmAnalysis()
{
	time_t start;
	time_t end;
	const char* temp = "Llama";
	
	start = getTime();
	linearSearch(temp);
	end = getTime();
	cout << "\nLinear Search:\t" << totalTime(start, end);
	
	bubbleSort();
	
	start = getTime();
	binarySearch(temp);
	end = getTime();
	cout << "\nBinary Search:\t" << totalTime(start, end);
	
	insertionSortDescending();
	
	start = getTime();
	bubbleSort();
	end = getTime();
	cout << "\nBubble Sort:\t" << totalTime(start, end);
	
	insertionSortDescending();
	
	start = getTime();
	selectionSort();
	end = getTime();
	cout << "\nSelection Sort:\t" << totalTime(start, end);
	
	insertionSortDescending();
	
	start = getTime();
	insertionSort();
	end = getTime();
	cout << "\nInsertion Sort:\t" << totalTime(start, end);
	
	start = getTime();
	insertionSortDescending();
	end = getTime();
	cout << "\nInsertion Sort Descending:\t" << totalTime(start, end);
	
	start = getTime();
	mergeSort(0, getNumMovies() - 1);
	end = getTime();
	cout << "\nMerge Sort:\t" << totalTime(start, end);
	
	insertionSortDescending();
	
	start = getTime();
	quickSort(0, getNumMovies() - 1);
	end = getTime();
	cout << "\nQuick Sort:\t" << totalTime(start, end);	
}