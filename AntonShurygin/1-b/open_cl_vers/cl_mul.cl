/*R"(*/

// First naive implementation
__kernel void naive_mul(const int M, const int N, const int K, const __global float* lhs,
                                                               const __global float* rhs,
                                                                     __global float* res) 
{
    // Thread identifiers
    const int global_row = get_global_id(0); // Row ID of C (0..M)
    const int global_col = get_global_id(1); // Col ID of C (0..N)
 

    // Compute a single element (loop over K)
    float acc = 0.0f;
    for (int k=0; k<K; k++) 

        acc += lhs[k*M + global_row] * rhs[global_col*K + k];
    
 
    // Store the result
    res[globalCol*M + globalRow] = acc;
}
/*"*/