/*
 *    This file is part of ACADO Toolkit.
 *
 *    ACADO Toolkit -- A Toolkit for Automatic Control and Dynamic Optimization.
 *    Copyright (C) 2008-2014 by Boris Houska, Hans Joachim Ferreau,
 *    Milan Vukov, Rien Quirynen, KU Leuven.
 *    Developed within the Optimization in Engineering Center (OPTEC)
 *    under supervision of Moritz Diehl. All rights reserved.
 *
 *    ACADO Toolkit is free software; you can redistribute it and/or
 *    modify it under the terms of the GNU Lesser General Public
 *    License as published by the Free Software Foundation; either
 *    version 3 of the License, or (at your option) any later version.
 *
 *    ACADO Toolkit is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *    Lesser General Public License for more details.
 *
 *    You should have received a copy of the GNU Lesser General Public
 *    License along with ACADO Toolkit; if not, write to the Free Software
 *    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */



 /**
  *    \file  simple_nlp_acado.cpp
  *    \author Guido Sanchez
  *    \date   2019
  */


#include <acado_optimal_control.hpp>
#include <acado_gnuplot.hpp>
#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

int main( ){

    USING_NAMESPACE_ACADO

    // INTRODUCE THE VARIABLES:
    // -------------------------
    Parameter x, y;

    // DEFINE A NLP:
    // ----------------------------------
    NLP nlp;
    nlp.minimize ( x*x + y*y );
    nlp.subjectTo( 0 <= x + y - 10 <= 0);


    // DEFINE AN OPTIMIZATION ALGORITHM AND SOLVE THE NLP:
    // ---------------------------------------------------
    OptimizationAlgorithm algorithm(nlp);

    algorithm.set( KKT_TOLERANCE, 1e-12 );
    algorithm.set( PRINTLEVEL, NONE );

    double avg_solvetime = 0.0;
    
    for (int i=0; i<1000; i++) {
        clock_t begin = clock();
        algorithm.solve();
        clock_t end = clock();
        double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
        cout << "-----" << endl;
        cout << "solve time = " << elapsed_secs << endl;
        algorithm.getParameters("simple_nlp_result.txt");
        avg_solvetime += elapsed_secs;
    }
    cout << "Average solve time = " << avg_solvetime/1000 << endl;

    return 0;
}



