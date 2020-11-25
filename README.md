Test task;


    Client input must match the following regex expression : \[((1|0)(,(1|0))*)?\]

    Examples of correct client input:
        [1,1,0,0,1,1,0,1]
        []
        [0,0,0]
        [1,1,1]
    
Server and client works on 40055 port;


recommended install steps:  
git clone --recurse-submodules  https://github.com/FrogKnowledge/TestTask  
cd TestTask/  
mkdir build  
cd build  
cmake ..  
cmake --build .  
