#include "stdafx.h"
#include "match_program.h"
#include "function.h"

match_program::match_program()
{
}


match_program::~match_program()
{
}



//对部门进行降序排列 根据人数限制
bool cmp(department &dep1, department &dep2) {
	return dep1.member_limit>dep2.member_limit;
}


//
bool cmp1(wishStu &tmp1, wishStu &tmp2) {
	return  tmp1.value > tmp2.value;
}

//
void match_program::match_algorithm() {


	for (int i = 0; i < dep_num; i++) {
		memset(wishtmp, 0, sizeof(wishtmp));
		for (int j = 0; j < stu_num; j++) {

			wishtmp[j].dep_index = i;
			wishtmp[j].stu_index = j;
			wishtmp[j].value = rank_value[j][i];
		}
        /*根据权值进行排序*/
		sort(wishtmp, wishtmp + stu_num, cmp1);  
												 
		addmitted[i].department_no = dep[i].department_no;

		for (int j = 0; j < stu_num; j++) {
			
			if (dep[i].member_limit == 0) break;

			if (wishtmp[j].value != 0) {
				if (stu[wishtmp[j].stu_index].flag == false) {
					addmitted[i].member[addmitted[i].memeber_num++] = stu[wishtmp[j].stu_index].student_no;

					stu[wishtmp[j].stu_index].flag = true;

					dep[i].member_limit--;

				}
                else
                {
                    continue;
                }
			}
            if (wishtmp[j].value == 0) { 
                break;
            }

		}
	}

	for (int i = 0; i < dep_num; i++) {
		if (addmitted[i].memeber_num == 0) {
			unlucky_depa[unluck_dep_num++].department_no = addmitted[i].department_no;
		}
	}
	for (int i = 0; i < stu_num; i++) {
		if (!stu[i].flag) {
			unlucky_student[unluck_stu_num++].student_sno = stu[i].student_no;
		}
	}

}
