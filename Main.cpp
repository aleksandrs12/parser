#include <iostream>
#include <fstream>
#include <vector>
#include <cstdio>
using namespace std;





int main() {

	struct coord3d {
		double x;
		double y;
		double z;
	};

	struct coord2d {
		double x;
		double y;
	};


	std::vector<coord3d> v;
	std::vector<coord2d> vt;
	std::vector<coord3d> vn;

	struct triangle{
		int points[3];
		int pos;
		int txPoints[3];
	};


	std::vector<triangle> triangles;

	struct object {
		std::vector<coord3d> v;
		std::vector<triangle> triangles;
	};



	FILE* my_file;
	fopen_s(&my_file, "untitled.obj", "r");



	if (!my_file) {
		cout << "File not created!";
	}
	else {
		char ch;
		char t[128];
		double t2[3];
		int i = 0;
		int i2 = 0;
		bool skip = false;

		while (!skip) {
			
			ch = fgetc(my_file);
			if (ch == EOF) {
				skip = true;
				break;
			}
			if (ch == '#') {
				while (ch != '\n') {
					ch = fgetc(my_file);
					if (ch == EOF) {
						skip = true;
						break;
					}
				}
			}
			else if (ch == 'v') {
				
				ch = fgetc(my_file);
				if (ch == 't') {
					ch = fgetc(my_file);
					while (ch != '\n') {
						if (ch == EOF) {
							skip = true;
							break;
						}
						
						t[i] = ch;
						ch = fgetc(my_file);
						
						if (ch == ' ') {
							t[i + 1] = 0;
							t2[i2] = std::atof(t);
							i2++;
							i = -1;
							//ch = fgetc(my_file);
						}
						i++;

					}
					t[i] = 0;
					t2[i2] = std::atof(t);
					t2[2] = 0;
					coord2d t22 = { t2[0], t2[1] };
					i2 = 0;
					vt.push_back(t22);
					i = 0;
					
				}

				else if (ch == 'n') {
					ch = fgetc(my_file);
					while (ch != '\n') {
						if (ch == EOF) {
							skip = true;
							break;
						}
						t[i] = ch;
						ch = fgetc(my_file);
						if (ch == ' ') {
							t[i + 1] = 0;
							t2[i2] = std::atof(t);
							i2++;
							i = -1;
							//ch = fgetc(my_file);
						}
						i++;

					}
					t[i] = 0;
					t2[i2] = std::atof(t);
					i2 = 0;
					coord3d t22 = { t2[0], t2[1], t2[2] };
					
					vn.push_back(t22);
					i = 0;

				}

				else {
					ch = fgetc(my_file);
					
					while (ch != '\n') {
						
						if (ch == EOF) {
							skip = true;
							break;
						}
						t[i] = ch;
						ch = fgetc(my_file);
						
						if (ch == ' ') {
							t[i + 1] = 0;
							t2[i2] = std::atof(t);
							i2++;
							i = -1;
							//ch = fgetc(my_file);
						}
						i++;

					}

					t[i] = 0;
					t2[i2] = std::atof(t);
					i2 = 0;
					coord3d t22 = { t2[0], t2[1], t2[2] };
					v.push_back(t22);
					i = 0;
				}
			}

			else if (ch == 'f') {
			
			}
			


			
		}
		fclose(my_file);
	}
	for (int b = 0; b < v.size(); b++) {
		printf("%f %f %f\n", v[b].x, v[b].y, v[b].z);
		
		
	}

	for (int b = 0; b < vt.size(); b++) {
		printf("%f %f\n", vt[b].x, vt[b].y);


	}

	for (int b = 0; b < vn.size(); b++) {
		printf("%f %f %f\n", vn[b].x, vn[b].y, vn[b].z);


	}
	return 0;
}