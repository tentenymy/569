#include "hw2_helper.h"
#include "p1a.h"

using namespace cv;
using namespace std;

const int HEIGHT = 128;
const int WIDTH = 128;
const int BYTEPERPIXEL = 1;
const int NUM_DATA = 25;

const string LIST_LABEL[3] = {"grass", "straw", "unknown"};
const int LIST_NUM_LABEL[3] = {36, 36, 24};
const int NUM_LABEL = 2;

const string FOLDER1 = "p1_image/p1_image_a/";






class ClassifierTexture
{
private:
    int filter_bank[25][25];
    Mat mat_feature_average[NUM_LABEL];
    string list_filename_label1[36];
    string list_filename_label2[36];
    string list_filename_unknown[24];
    string list_label_unknown[24];

    vector <Mat> mat_feature;

    // Generate File name list
    string Get_Filename (string label, int num) {
        string str_num;
        num++;
        if (num < 10)
            str_num = "0" + to_string(num);
        else
            str_num = to_string(num);
        return label + "_" + str_num + ".raw";
    }
    void Get_List_Filename () {
        string filename = "";
        for (int i = 0; i < LIST_NUM_LABEL[0]; i++)
        {
            filename = FOLDER1 + Get_Filename(LIST_LABEL[0], i);
            list_filename_label1[i] = filename;
        }
        for (int i = 0; i < LIST_NUM_LABEL[1]; i++)
        {
            filename = FOLDER1 + Get_Filename(LIST_LABEL[1], i);
            list_filename_label2[i] = filename;
        }
        for (int i = 0; i < LIST_NUM_LABEL[2]; i++)
        {
            filename = FOLDER1 + Get_Filename(LIST_LABEL[2], i);
            list_filename_unknown[i] = filename;
        }
    }
    // Create Filter
    void Set_Filter() {
        cout << "Set_filter" << endl;
        int coef_laws_filter[5][5] = {{1, 4, 6, 4, 1}, {-1, -2, 0, 2, 1}, {-1, 0, 2, 0, -1},
                                      {-1, 2, 0, -2, 1}, {1, -4, 6, -4, 1}};
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                for (int m = 0; m < 5; m++) {
                    for (int n = 0; n < 5; n++) {
                        filter_bank[i * 5 + j][m * 5 + n] = coef_laws_filter[i][m] * coef_laws_filter[j][n];
                    }
                }
            }
        }
    }
    void Print_Filter() {
        cout << "Print_Filter" << endl;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                cout << "(" << j << ", " << i << ")" << endl;
                for (int m = 0; m < 5; m++) {
                    for (int n = 0; n < 5; n++) {
                        cout << filter_bank[j * 5 + i][m * 5 + n] << " ";
                    }
                    cout << endl;
                }
                cout << endl;
            }
        }
    }
    int *Get_Window(int i, int j, int height, int width, int half_window) {
        // top, bottom, left, right
        int window[4] = {i - 2, i + 2, j - 2, j + 2};
        if (window[0] < 0)
            window[0] = 0;
        if (window[2] < 0)
            window[2] = 0;
        if (window[1] > height - 1)
            window[1] = height - 1;
        if (window[3] > width - 1)
            window[3] = width - 1;
        int *res = window;
        return res;
    }
public:
    ClassifierTexture() {
        Get_List_Filename();
        Set_Filter();
        string temp_list_label_unknown[24] =
                {"straw", "straw", "grass", "grass", "grass", "straw",
                 "grass", "straw", "straw", "grass", "grass", "grass",
                "straw", "grass", "straw" , "straw", "straw", "straw",
                "grass", "grass", "grass", "straw", "straw", "grass"};
        for (int i = 0; i < 24; i++) {
            list_label_unknown[i] = temp_list_label_unknown[i];
        }
    }
    // p1a1: Feature Extraction
    double *Extract_Feature (Img *pt_img, int height, int width, int byteperpixel) {
        //cout << "Feature Extract: " << endl;
        // 1. Set original image
        int img[128 * 128];
        for (int i = 0; i < 128; i++) {
            for (int j = 0; j < 128; j++) {
                img[i * 128 + j] = (int)*pt_img++;
            }
        }
        // 2. Subtract local mean from original image
        int img_mean[128 * 128];
        int img_subtract[128 * 128];
        for (int i = 0; i < 128; i++) {
            for (int j = 0; j < 128; j++) {
                int temp_num = 0;
                double temp_total = 0;
                int *window = Get_Window(i , j, 128, 128, 2);
                for (int m = window[0]; m <= window[1]; m++) {
                    for (int n = window[2]; n <= window[3]; n++) {
                        temp_total += img[m * 128 + n];
                        temp_num++;
                    }
                }
                img_mean[i * 128 + j] = round(temp_total/temp_num);
                img_subtract[i * 128 + j] = img[i * 128 + j] - img_mean[i * 128 + j];
            }
        }
        // 3. Apply Laws' filter to subtracted image and get the average of energy of each pixel
        double img_energy[25][128 * 128];
        double pixel_num = 128 * 128;
        double pixel_total[25];
        for (int k = 0; k < 25; k++) {
            pixel_total[k] = 0;
            for (int i = 0; i < 128; i++) {
                for (int j = 0; j < 128; j++) {
                    int temp_num = 0;
                    double temp_total = 0;
                    int *window = Get_Window(i , j, 128, 128, 2);
                    for (int m = window[0]; m <= window[1]; m++) {
                        for (int n = window[2]; n <= window[3]; n++) {
                            temp_total += img_subtract[m * 128 + n] * filter_bank[k][5 * (2 + m - i) + (2 + n - j)];
                            temp_num ++;
                        }
                    }
                    img_energy[k][128 * i + j] = (temp_total / temp_num) * (temp_total / temp_num);
                    pixel_total[k] += img_energy[k][128 * i + j];
                }
            }
            pixel_total[k] = pixel_total[k] / pixel_num;
        }
        // 4. Normalization X' = (X - Xmin) / (Xmax - Xmin)
        double pixel_min = pixel_total[0];
        double pixel_max = pixel_total[0];
        for (int i = 1; i < 25; i++) {
            if (pixel_total[i] < pixel_min) {
                pixel_min = pixel_total[i];
            }
            if (pixel_total[i] > pixel_max) {
                pixel_max = pixel_total[i];
            }
        }
        for (int i = 0; i < 25; i++) {
            pixel_total[i] = (pixel_total[i] - pixel_min) / (pixel_max - pixel_min);
        }
        double *res = pixel_total;
        return res;
    }
    void Set_Feature_Known () {
        cout << "Set_Feature_Known" << endl;
        // Read all labeled image and get mean
        ImgMatOperator img_op;
        Img *temp_img;
        double *temp_feature;
        double feature_average[NUM_LABEL][NUM_DATA] = {};
        for (int i = 0; i < 36; i++) {
            temp_img = img_op.Img_Raw_Read(list_filename_label1[i], HEIGHT, WIDTH, BYTEPERPIXEL);
            temp_feature = Extract_Feature(temp_img, HEIGHT, WIDTH, BYTEPERPIXEL);
            for (int j = 0; j < NUM_DATA; j++) {
                feature_average[0][j] += temp_feature[j] /36;
            }
            Mat temp_mat = Mat(1, NUM_DATA, CV_64F, temp_feature).clone();
            mat_feature.push_back(temp_mat);
        }
        for (int i = 0; i < 36; i++) {
            temp_img = img_op.Img_Raw_Read(list_filename_label2[i], HEIGHT, WIDTH, BYTEPERPIXEL);
            temp_feature = Extract_Feature(temp_img, HEIGHT, WIDTH, BYTEPERPIXEL);
            for (int j = 0; j < NUM_DATA; j++) {
                feature_average[1][j] += temp_feature[j] /36;
            }
            Mat temp_mat = Mat(1, NUM_DATA, CV_64F, temp_feature).clone();
            mat_feature.push_back(temp_mat);
        }
        // Save in Mat
        for (int i = 0; i < NUM_LABEL; i++) {
            mat_feature_average[i] = Mat(1, NUM_DATA, CV_64F, feature_average[i]).clone();
        }
    }
    void Set_Feature_Unknown() {
        cout << "Set_Feature_Unknown" << endl;
        // Read all labeled image and get mean
        ImgMatOperator img_op;
        Img *temp_img;
        double *temp_feature;
        for (int i = 0; i < 24; i++) {
            temp_img = img_op.Img_Raw_Read(list_filename_unknown[i], HEIGHT, WIDTH, BYTEPERPIXEL);
            temp_feature = Extract_Feature(temp_img, HEIGHT, WIDTH, BYTEPERPIXEL);
            Mat temp_mat = Mat(1, NUM_DATA, CV_64F, temp_feature).clone();
            mat_feature.push_back(temp_mat);
        }
    }
    void Print_Feature_Average() {
        // Print average of each label
        cout << "Print_Feature_Average" << endl;
        for (int i = 0; i < NUM_LABEL; i++) {
            cout << LIST_LABEL[i] << endl;
            cout << mat_feature_average[i] << endl << endl;
        }
    }
    void Print_Feature() {
        cout << "Print_Feature" << endl;
        for (int i = 0; i < mat_feature.size(); i++) {
            cout << mat_feature[i] << endl;
        }
    }
    // p1a2: MM
    int Get_Minimum_Mean_Distance (int no_feature, string label) {
        Mat temp_covar, temp_covar_invert;
        double distance[NUM_LABEL];
        double min_distance = 100;
        string min_label = "";
        for (int i = 0; i < NUM_LABEL; i++) {
            calcCovarMatrix(mat_feature[no_feature], temp_covar, mat_feature_average[i], CV_COVAR_NORMAL|CV_COVAR_ROWS|CV_COVAR_USE_AVG);
            invert(temp_covar, temp_covar_invert, DECOMP_SVD);
            distance[i] = Mahalanobis(mat_feature[no_feature], mat_feature_average[i], temp_covar);
            if (min_distance > distance[i]) {
                min_distance = distance[i];
                min_label = LIST_LABEL[i];
            }
        }
        if (min_label != label) {
            cout << label << " " << no_feature << ": " << min_label << " (*)" << endl;
            return 1;
        }
        else  {
            cout << label << " " << no_feature << ": " << min_label << endl;
            return 0;
        }

    }

    void Classifier_MM() {
        cout << "Minimum Mean Distance" << endl;
        ImgMatOperator img_op;
        int count_error = 0;
        // Read Extracted Feature
        for (int k = 0; k < 36; k++) {
            count_error += Get_Minimum_Mean_Distance (k, LIST_LABEL[0]);
        }
        for (int k = 0; k < 36; k++) {
            count_error += Get_Minimum_Mean_Distance (k + 36, LIST_LABEL[1]);
        }
        for (int k = 0; k < 24; k++) {
            count_error += Get_Minimum_Mean_Distance (k + 72, list_label_unknown[k]);
        }
        double error_rate = 100.0 * count_error / (36.0 + 36.0 + 24.0);
        cout << "ERROR RATE: " << error_rate << endl;
    }
    void Test()
    {
        // Extract_Feature
        ImgMatOperator img_op;
        char filename[] = "p1_image/p1_image_a/straw_01.raw";
        Img *img = img_op.Img_Raw_Read(filename, 128, 128, 1);
        double *feature_vector = Extract_Feature(img, 128, 128, 1);
        for (int i = 0; i < 25; i++) {
            cout << *feature_vector++ << endl;
        }
    }
};


void Prob1a()
{
    cout << "Prob1a" << endl;
    ClassifierTexture classifier = ClassifierTexture();
    classifier.Set_Feature_Known();
    classifier.Set_Feature_Unknown();

    //classifier.Print_Feature_Average();
    //classifier.Print_Feature();
    classifier.Classifier_MM();
}

int main(int argc, char *argv[])
{
    cout << "Problem 1" << endl;
    Prob1a();

    return 0;
}

