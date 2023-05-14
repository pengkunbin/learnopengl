#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

// 视图宽度
int width = 800;
// 视图高度
int height = 600;

// 用户改变窗口的大小的时候，视口也应该被调整的回掉函数
void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

// 监听键盘操作的回调函数
void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// 初始化着色器
void initTriangleShader(unsigned int &shaderProgram, unsigned int &shaderYellowProgram, unsigned int (&VAOs)[2])
{
    // 编译着色器
    const char *vertexShaderSource = "#version 330 core\n"
                                     "layout (location = 0) in vec3 aPos;\n"
                                     "void main()\n"
                                     "{\n"
                                     "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                                     "}\0";
    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    // 片段着色器
    const char *fragmentShaderSource = "#version 330 core\n"
                                       "out vec4 FragColor;\n"
                                       "void main()\n"
                                       "{\n"
                                       "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
                                       "}\0";
    // 片段着色器-黄色
    const char *fragmentShaderYellowSource = "#version 330 core\n"
                                             "out vec4 FragColor;\n"
                                             "void main()\n"
                                             "{\n"
                                             "   FragColor = vec4(1.0f, 1.0f, 0.0f, 1.0f);\n"
                                             "}\n\0";

    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    // 创建一个黄色shader
    unsigned int fragmentYellowShader;
    fragmentYellowShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentYellowShader, 1, &fragmentShaderYellowSource, NULL);
    glCompileShader(fragmentYellowShader);

    // 创建一个着色器对象
    shaderProgram = glCreateProgram();
    shaderYellowProgram = glCreateProgram();

    // 链接着色器
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    // 链接黄色着色器
    glAttachShader(shaderYellowProgram, vertexShader);
    glAttachShader(shaderYellowProgram, fragmentYellowShader);
    glLinkProgram(shaderYellowProgram);

    // 激活该着色器
    glUseProgram(shaderProgram);
    glUseProgram(shaderYellowProgram);

    // 删除链接后的着色器，节省空间
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    glDeleteShader(fragmentYellowShader);

    // 顶点着色器
    float firstTriangle[] = {
        // 第一个三角形
        -0.5f, -0.5f, 0.0f,
        -0.5f, 0.5f, 0.0f,
        0.5f, 0.5f, 0.0f};

    // 顶点着色器
    float secondTriangle[] = {
        // 第二个三角形
        1.5f, 1.5f, 0.0f,
        1.5f, 0.5f, 0.0f,
        0.5f, 0.5f, 0.0f};

    // 生成VBO对象
    unsigned int VBOs[2];
    glGenVertexArrays(2, VAOs);
    glGenBuffers(2, VBOs);

    // 将顶点数据复制到VBO中
    glBindVertexArray(VAOs[0]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(firstTriangle), firstTriangle, GL_STATIC_DRAW);
    // 指定顶点属性的格式和位置
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);

    // 将顶点数据复制到VBO中
    glBindVertexArray(VAOs[1]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(secondTriangle), secondTriangle, GL_STATIC_DRAW);
    // 指定顶点属性的格式和位置
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void *)0);
    glEnableVertexAttribArray(0);

    // 解绑VBO和VAO对象
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

int main()
{
    // 初始化GLFW
    glfwInit();

    // 告诉GLFW我们要使用的OpenGL版本是3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    std::cout << "init successfully" << std::endl;

    // 创建一个宽800 高600的窗口
    GLFWwindow *window = glfwCreateWindow(width, height, "LearnOpenGL", NULL, NULL);

    // 异常情况判断
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    glViewport(0, 0, width, height);

    // 注册窗口大小回调函数
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    std::cout << "start render" << std::endl;

    // 初始化着色器
    unsigned int shaderProgram, shaderYellowProgram, VAOs[2];
    initTriangleShader(shaderProgram, shaderYellowProgram, VAOs);

    // 循环渲染视图窗口
    while (!glfwWindowShouldClose(window))
    {
        // 输入
        processInput(window);

        // 渲染指令-将画面变成蓝绿色
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // 渲染第一个三角形
        glUseProgram(shaderProgram);
        glBindVertexArray(VAOs[0]);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        // 渲染第二个三角形
        glUseProgram(shaderYellowProgram);
        glBindVertexArray(VAOs[1]);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        // 检查并调用事件，交换缓冲
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    return 0;
}