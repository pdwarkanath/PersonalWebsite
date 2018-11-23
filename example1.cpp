#include <ilcplex/ilocplex.h>

ILOSTLBEGIN

static void
	populatebyrow (IloModel model, IloNumVarArray var, IloRangeArray con);

int main (void){
	
	// Setting up the CPLEX environment

	IloEnv env;

	// CPLEX solution block

	try {
		
		// Declaring the objects
		
		IloModel model(env);
		IloNumVarArray var (env);
		IloRangeArray con(env);
		populatebyrow(model, var, con);

		// Solving using CPLEX

		IloCplex cplex(model);
		cplex.solve();

		// Output solutions

		env.out() << "Solution status = " << cplex.getStatus() << endl;
		env.out() << "Solution value = " << cplex.getObjValue() << endl;

		IloNumArray vals(env);
		cplex.getValues(vals, var);
		env.out() << "Values = " << vals << endl;

		IloNumArray slacks(env);
		cplex.getSlacks(slacks, con);
		env.out() << "Slacks = " << slacks << endl;

		// Write model to file

		cplex.exportModel("ipex1.lp");

	}
	
	// Error handling

	catch (IloException e){
		cerr << "Concert exception caught: " << e << endl;
	}

	catch (...){
		cerr << "Unknown exception caught." << endl;
	}
	
	// End environment

	env.out() << "Press return to exit..." << endl;
	std::getchar();
	env.end();
	return 0;

}

static void
	populatebyrow (IloModel model, IloNumVarArray x, IloRangeArray c){
		
		// retrieve model environment

		IloEnv env = model.getEnv();

		// Define variables
		
		x.add(IloNumVar(env, 0.0, IloInfinity, ILOINT));
		x.add(IloNumVar(env, 0.0, IloInfinity, ILOINT));
		
		// Add objective

		model.add(IloMaximize(env, 1.00 * x[0] + 0.64 * x[1] ));

		// Add constraints

		c.add( 50 * x[0] + 31 * x[1] <= 250);
		c.add( 3 * x[0] - 2 * x[1] >= -4);
		model.add(c);
}