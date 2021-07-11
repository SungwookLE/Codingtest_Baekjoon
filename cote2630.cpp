/* 쿼드트리를 만드는 문제
https://chessire.tistory.com/entry/%EC%BF%BC%EB%93%9C%ED%8A%B8%EB%A6%ACQuad-tree

백준: https://www.acmicpc.net/problem/2630

쿼드트리란?
트리 자료구조중 하나로 부모 노드 아래에 자식 노드를 4개(Quad)씩 가지고 있는 트리.
이미지 용량, 충돌, 컬링 등 다양한 곳에서 최적화 기법으로 사용되고 있음
https://sungwookle.github.io/algorithm/Baekjoon_2630/
*/

// 입력으로 주어진 종이의 한 변의 길이 N과 각 정사각형칸의 색(하얀색 또는 파란색)이 주어질 때
// 잘라진 하얀색 색종이와 파란색 색종이의 개수를 구하는 프로그램을 작성하시오.

#include <iostream>
#include <vector>

class solver_2630{
    public:
    void insert(){
        std::cin >> N;
        for(int j=0; j < N ; ++j){
            std::vector<int> one_rect(N);
            for(int i=0 ; i < N ; ++i){
                std::cin >> one_rect[i];
            }
            rect.push_back(one_rect);
        }
    }

    void monitor_rect(){
        std::cout << "RECTANGULAR: \n";
        for (auto one : rect){
            for(auto ele : one)
                std::cout << ele << " ";
            std::cout << "\n";
        }
    }

    void quadTree(int beginX, int beginY, int size){
        int beginData = rect[beginY][beginX];
        bool isCombinable = true;

        for (int y = beginY; y < beginY+size ; ++y){
            for (int x = beginX; x < beginX +size; ++x){
                if (beginData != rect[y][x]){
                    isCombinable = false;
                    break;
                }
            }
            if (isCombinable==false)
                break;
        }

        if (isCombinable){
            //std::cout << beginData ;

            if (beginData == 0)
                white+=1;
            else if (beginData == 1)
                blue+=1;
            
        }
        else{
            int halfSize = size/2;
            //std::cout << "(";
            quadTree(beginX, beginY, halfSize);
            quadTree(beginX + halfSize , beginY, halfSize);
            quadTree(beginX, beginY+halfSize, halfSize);
            quadTree(beginX+halfSize, beginY+halfSize, halfSize);
            //std::cout << ")";
        }
    }

    void print_answer(){
        std::cout << white << std::endl;
        std::cout << blue << std::endl;
    }

    int N;
    private:
    std::vector<std::vector<int>> rect;
    int white = 0 , blue =0;
};

int main(){
    solver_2630 solver;
    solver.insert();
    solver.quadTree(0,0,solver.N);
    solver.print_answer();

    return 0;
}