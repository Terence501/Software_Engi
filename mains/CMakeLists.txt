#add the executable target named HelloWorld
add_executable(HelloWorld hello.cpp)
target_link_libraries(HelloWorld PRIVATE basic)
install(TARGETS HelloWorld DESTINATION bin)


#add the executable target named SimTown
add_executable(Simtown sim_town.cpp)
target_link_libraries(Simtown PRIVATE sim)
install(TARGETS Simtown DESTINATION bin)

