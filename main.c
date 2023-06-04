#include "glad/glad.c"
#include <GLFW/glfw3.h>
#include "shaders.h"
#define APP_DEBUG


float vertices[] = {
     0.5f,  0.5f, 0.0f,  // top right
     0.5f, -0.5f, 0.0f,  // bottom right
    -0.5f, -0.5f, 0.0f,  // bottom left
    -0.5f,  0.5f, 0.0f   // top left 
};

unsigned int indices[] = {  // note that we start from 0!
    0, 1, 3,   // first triangle
    1, 2, 3    // second triangle
};


// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}
int main () {
    
    #ifdef APP_DEBUG
    if (!glfwInit()) {
        printf("Could not initialize GLFW!");
        return 1;
    }
    #endif
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    GLFWwindow* window = glfwCreateWindow(640, 480, "ctoupiti", NULL, NULL);
    #ifdef APP_DEBUG
        if (!window) {
            printf("Could not open window!" );
            glfwTerminate();
            return 1;
        }
    #endif
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    #ifdef APP_DEBUG
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            printf("Failed to initialize GLAD");
            return -1;
        }  
    #endif

    // Vertex Shader Definition
    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vert_glsl, NULL);
    glCompileShader(vertexShader);
    #ifdef APP_DEBUG
    {
        int  success;
        char infoLog[512];
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
        if(!success)
        {
            glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
            printf("ERROR::SHADER::VERTEX::COMPILATION_FAILED %s \n", infoLog );
        }
    }
    #endif


    // Fragment Shader 
    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &frag_glsl, NULL);
    glCompileShader(fragmentShader);
    #ifdef APP_DEBUG
    {
        int  success;
        char infoLog[512];
        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
        if(!success)
        {
            glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
            printf("ERROR::SHADER::VERTEX::COMPILATION_FAILED %s \n", infoLog );
        }
    }
    #endif

    // Shader program
    
    unsigned int shaderProgram;
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    #ifdef APP_DEBUG
    {
        int  success;
        char infoLog[512];
        glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
        if(!success) {
            glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
            printf("ERROR::SHADER::SHADERPROGRAMVERTEX::COMPILATION_FAILED %s \n", infoLog );
        }
    }
    #endif



    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);  
    // Vertex Buffer Object, Vertex Array 
  
    //
    unsigned int VAO, VBO, EBO;
    glGenBuffers(1, &VBO);  
    glGenBuffers(1, &EBO);
    glGenVertexArrays(1, &VAO);  
    glBindVertexArray(VAO);


    // 0. copy our vertices array in a buffer for OpenGL to use
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // 1. then set the vertex attributes pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);  
    // 2. use our shader program when we want to render an object


    while (!glfwWindowShouldClose(window)) {
     
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProgram);
        double timeValue = glfwGetTime();
        int fGlobalTimeLocation = glGetUniformLocation(shaderProgram, "fGlobalTime");
        glUniform1f(fGlobalTimeLocation,timeValue);
        glBindVertexArray(VAO);
        //glDrawArrays(GL_TRIANGLES, 0, 3);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glfwSwapBuffers(window);
        glfwPollEvents();
     
    }
    
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    glDeleteProgram(shaderProgram);

    glfwDestroyWindow(window);
    
    glfwTerminate();
    return 0;
}

