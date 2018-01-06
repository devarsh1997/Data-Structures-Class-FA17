import numpy as np
import scipy.sparse as sp
import scipy.sparse.linalg as la
import matplotlib.pyplot as plt
import time

def fast_solve(Ax, f):
    #Implement this as part of step 3
    return f