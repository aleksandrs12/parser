#include <iostream>
#include <fstream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <iterator>
#include <numeric>

using namespace std;




struct coord3d {
	double x;
	double y;
	double z;
};

struct coord2d {
	double x;
	double y;
};
struct triangle {
	int points[3];
	int pos;
	int txPoints[3];
};
struct object {
	float pos;
	std::vector<triangle> triangles;
};



std::vector<object> parse() {

	


	std::vector<coord3d> v;
	std::vector<coord2d> vt;
	std::vector<coord3d> vn;

	


	std::vector<triangle> triangles;

	
	std::vector<object> objects;


	FILE* my_file;
	fopen_s(&my_file, "untitled1.obj", "r");



	if (!my_file) {
		cout << "File not created!";
	}
	else {
		char ch;
		char t[128];
		double t2[3];
		int i = 0;
		int i2 = 0;
		int i3 = 0;
		bool skip = false;
		int n = 0;
		int tr[3];
		int trTex[3];
		int pos;
		bool firstO = true;

		while (!skip) {

			ch = fgetc(my_file);
			if (ch == EOF) {
				skip = true;
				break;
			}
			if (ch == '#' || ch == 's') {
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
				i = 0;
				i2 = 0;
				i3 = 0;
				n = 0;
				ch = fgetc(my_file);
				ch = fgetc(my_file);

				for (ch; ch != '\n'; ch = fgetc(my_file)) {
					if (ch == EOF) {
						skip = true;
						break;
					}

					if (ch == '/' || ch == ' ') {
						//printf("%d", n);
						if (n == 0) {
							t[i] = 0;
							tr[i2] = std::atoi(t);
							i2++;
							i = 0;
							n++;
						}
						else if (n == 1) {
							t[i] = 0;
							trTex[i3] = std::atoi(t);
							i3++;
							i = 0;
							n++;
						}
						else if (n == 2) {
							t[i] = 0;
							pos = std::atoi(t);
							

							i = 0;
							n = 0;
						}
					}
					else {
						t[i] = ch;
						i++;
					}

				}
				triangles.push_back(triangle { {tr[0], tr[1], tr[2]}, pos, {trTex[0], trTex[1], trTex[2]} });
			}

			else if (ch == 'o') {
			if (firstO)
				firstO = false;
			else {
				objects.push_back(object { 1.0, triangles });
				triangles.clear();
				}
			}
			

	}



			
		
		objects.push_back(object { 1.0, triangles });

		fclose(my_file);
		for (int i = 0; i < objects.size(); i++) {
			printf("%s\n", "ABDULA BABAI");

			for (int b = 0; b < objects[i].triangles.size(); b++) {

				printf("%d %d %d\n", objects[i].triangles[b].points[0], objects[i].triangles[b].points[1], objects[i].triangles[b].points[2]);
				printf("%d\n", objects[i].triangles[b].pos);



			}
		}

		
	}
	return objects;
}

int main() {
	parse();
}




