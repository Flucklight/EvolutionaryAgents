// ***************************************************
// A very simple example program for the TSearch class
// ***************************************************

#include "TSearch.h"


// A simple 2D inverted quadratic evaluation function

double Evaluate(TVector<double> &v, RandomState &)
{
	double x = MapSearchParameter(v[1], -10, 10),
		y = MapSearchParameter(v[2], -10, 10),
		z = MapSearchParameter(v[3], -10, 10);
	if (z == 0)
		return 0;
	else
		return (x * x + y * y) / (z * z);
}


// The main program

int main (int argc, const char* argv[]) {
  TSearch s(3);
    
  // Configure the search
  s.SetRandomSeed(87632455);
  s.SetEvaluationFunction(Evaluate);
  s.SetSelectionMode(RANK_BASED);
  s.SetReproductionMode(HILL_CLIMBING);
  s.SetPopulationSize(1000);
  s.SetMaxGenerations(250);
  s.SetMutationVariance(0.1);
  s.SetCrossoverProbability(0.5);
  s.SetCrossoverMode(TWO_POINT);
  s.SetMaxExpectedOffspring(1.1);
  s.SetElitistFraction(0.1);
  s.SetSearchConstraint(1);
  s.SetCheckpointInterval(5);
    
  // Run the search
  s.ExecuteSearch();
  
  // Display the best individual found
  cout << s.BestIndividual() << endl;

  return 0;
}
