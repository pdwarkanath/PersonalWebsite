#include <ilcplex/ilocplex.h>

ILOSTLBEGIN

int main(void){
	IloEnv env;
	try {
		// Declare parameters

		IloNumArray minArray(env), maxArray(env), cost(env);
		IloNum demand;
		
		// Read data file
		
		ifstream in("rates.dat");
		in >> minArray >> maxArray >> cost >> demand;
     
		// Create model

		IloModel mdl(env);

		// Define variables

		IloNumVarArray production(env);
		IloInt generators = minArray.getSize();

		
		// Set upper and lower bounds for variables

		for (IloInt j = 0; j < generators; j++) {
			production.add(IloNumVar(env, minArray[j], maxArray[j]));
		}

		// Build objective function expression

		mdl.add(IloMinimize(env, IloScalProd(cost, production)));
		
		// Demand constraint

		mdl.add(IloSum(production) >= demand);

		// Solve and output solutions to a file

		IloCplex cplex(mdl);
		  cplex.exportModel("rates.lp");
		  ofstream f_out("rates.sol");
		  if (cplex.solve()) {
			 
			 f_out << "Solution status: " << cplex.getStatus() << endl;
			 for (IloInt j = 0; j < generators; j++) {
				f_out << "generator " << j << ": "
							<< cplex.getValue(production[j]) << endl;
			 }
			 f_out << "Total cost = " << cplex.getObjValue() << endl;
		  }
		  else {
			  f_out << "No solution" << endl;
		  cplex.printTime();
	   }
	}
	catch (IloException& ex) {
		cerr << "Error: " << ex << endl;
	}
	catch (...) {
		cerr << "Error" << endl;
	}
	env.end();
	return 0;
}

