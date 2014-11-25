#include <joint_bayes.h>

void save_mat(Mat mat,char* savefile)
{
  ofstream ofs(savefile);
  ofs<<mat.rows<<" "<<mat.cols<<"\n";
  for(int i = 0; i < mat.rows; i++)
  {
    for(int j = 0; j < mat.rows; j++)
      ofs<<mat.at<float>(i,j)<<" ";
      ofs<<"\n";
  }
  ofs.clear();
  ofs.close();
}
void read_mat(Mat &mat, char* loadfile)
{
        ifstream ifs(loadfile);
        ifs >> m;
        ifs >> n;
        mat.creat(m, n, CV_32F);
        for(int i = 0; i < m; i++)                
          for(int j = 0; j < n; j++)
                        ifs>>mat.at<float>(i,j);

}

Mat cal_PCA( map<string, Mat> data, int n_reduced, Mat& eigenvectors)
{
        map<string ,Mat >::iterator iter;
        Mat all;
        vector<string> label;
        int count = 0;
        for(iter = data.begin(); iter != data.end(); iter++)
        {
                md = iter->second.rows;
                nd = iter->second.cols;
                for(int i = 0; i < md; i++)
                {
                        label.push_back(iter->first);
                        all.push_back(iter->second.row(i));
                }
                count += md;
        }

        PCA pca(all,Mat(),CV_PCA_DATA_AS_ROW,n_reduced);

        eigenvectors= pca.eigenvectors.clone();

        return pca.project(all);
}

