int Err(int code){
    switch(code){
        case 0:
            std::cout << "Err 0x00" << std::endl;
            std::cout << "when opening a file" << std::endl;
            exit(1);
            break;
        case 1:
            std::cout << "Err 0x01" << std::endl;
            std::cout << "cycle has not been opened" << std::endl;
            exit(1);
            break;
        case 2:
            std::cout << "Err 0x02" << std::endl;
            std::cout << "one or more cycles were not closed" << std::endl;
            exit(1);
            break;
    }
    return 0;
}