from casadi import *
import time

x = MX.sym("x", 2)
f = x[0]*x[0] + x[1]*x[1]
g = x[0]+x[1]-10;

nlpoptions = {
    "ipopt" : {
        "print_level" : 0,
        # "max_cpu_time" : 60,
        "linear_solver" : "mumps",  # Comment this line if you don't have MA27
        "sb" : "yes",
        #"hessian_approximation": "limited-memory",
        "tol": 1e-3,
        # "acceptable_tol": 1e-3,
        # "max_iter" : 100,
    },
    "print_time" : False,
}

solver = nlpsol("solver", "ipopt", {"x": x, "f": f, "g": g}, nlpoptions)

# solver.generate_dependencies("nlp.c");


# os.system("gcc -fPIC -shared -O3 nlp.c -o nlp.so");
# solver = nlpsol("solver", "ipopt", "nlp.so")

arg = {}
arg["lbx"] = -inf
arg["ubx"] =  inf
arg["lbg"] =  0
arg["ubg"] =  inf
arg["x0"] = 0


Ntrials = 1000
avg_solvetime = 0.0;
solvetime = 0.0

for i in xrange(Ntrials):
    solvetime = -time.time()
    sol = solver(**arg)
    solvetime += time.time()

    print("-----")
    print(("%d/%d: %5.3g s to solve") % (i+1, Ntrials, solvetime))
    print("objective at solution = ", sol["f"])
    print("primal solution = ", sol["x"])
    print("dual solution (x) = ", sol["lam_x"])
    print("dual solution (g) = ", sol["lam_g"])

    avg_solvetime += solvetime

print(("Average solve time %5.3g") % (avg_solvetime/Ntrials))
