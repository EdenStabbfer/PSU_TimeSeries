#include <cmath>
#include <cstdint>

#define API __declspec(dllexport)

extern "C" {
    API double add(double* array, int n) {
        double sum{0};
        for (int i{0}; i < n; i++) {
            sum += array[i];
        }
        return sum;
    }

    inline double dist(double* shapelets, int nSubseqLen, int nShapeletLength,
                    int s_subseq_idx, int s_shapelet_idx,
                    int r_subseq_idx, int r_shapelet_idx) {
        double sum = 0;
        for (int i{0}; i < nShapeletLength; i++) {
            int s_idx = nShapeletLength*(s_subseq_idx*nSubseqLen + s_shapelet_idx) + i;
            int r_idx = nShapeletLength*(r_subseq_idx*nSubseqLen + r_shapelet_idx) + i;
            sum += std::pow(shapelets[s_idx] - shapelets[r_idx], 2);
        }
        return sum;
    }

    // API void compute_distances(int* classes, int nClasses,
    //                            double* shapelets, int nShapelets, int nShapeletLength,
    //                            int subseq_idx, int shapelet_idx,
    //                            int* outClasses, double* outDists) {
    // double d{0}, min_dist {0};
    // int c{0};
    // for (int i{0}; i < nClasses; i++) {
    //     c = classes[i];
    //     if (i == subseq_idx) {
    //         outDists[i] = 0.0;
    //         outClasses[i] = c;
    //         continue;
    //     }

    //     min_dist = dist(shapelets, nShapelets, nShapeletLength, subseq_idx, shapelet_idx, i, 0);
    //     for (int j{0}; j < nShapelets; j++) {
    //         d = dist(shapelets, nShapelets, nShapeletLength, subseq_idx, shapelet_idx, i, j);
    //         if (d < min_dist)
    //             min_dist = d;
    //     }
    //     outClasses[i] = c;
    //     outDists[i] = min_dist;
    // }
        

    }
    
    API struct TS_Array {
        uint32_t    classIdx;
        uint32_t    length;
        double*     values;
    };
    
    API void compute_distances(TS_Array* ts, 
                               uint32_t tsLen, uint32_t shapeletLen, 
                               uint32_t tsIdx, uint32_t shapeletIdx, 
                               TS_Array* outDists) {
        double d{0}, min_dist {0};
        for (int i{0}; i < tsLen; i++) { // Go through subsequences
            if (i == tsIdx) {
                outDists[i].classIdx = ts[i].classIdx;
                outDists[i].values = c;
                continue;
            }

            min_dist = dist(shapelets, nShapelets, nShapeletLength, subseq_idx, shapelet_idx, i, 0);
            for (int j{0}; j < nShapelets; j++) {
                d = dist(shapelets, nShapelets, nShapeletLength, subseq_idx, shapelet_idx, i, j);
                if (d < min_dist)
                    min_dist = d;
            }
            outClasses[i] = c;
            outDists[i] = min_dist;
        }
    }


    // API extractShapelets(TimeSeris* ts, uint32_t ts_length, uint32_t min_len, uint32_t max_len, uint32_t limit, bouble g=0.05) {

    // }
    
}