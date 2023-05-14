# 你好，三角形
渲染管线流程：
![渲染管线流程](./img/pipeline.png)
## VAO（Vertex Array Object）和VBO（Vertex Buffer Object）
以下解释均来自GPT3.5

VAO是用来存储顶点属性状态的对象，它包含了多个顶点属性指针（VertexAttribPointer）的状态，以及顶点属性指针的启用状态（EnableVertexAttribArray）。VAO可以记录下当前的顶点属性状态，以便在渲染时快速设置顶点属性。

VBO是用来存储顶点数据的缓冲区对象，它可以将顶点数据存储在显存中，以便在渲染时快速访问。使用VBO可以提高渲染性能，因为它可以减少CPU和GPU之间的数据传输次数。

在OpenGL中，VAO和VBO通常是一起使用的。VAO用于记录顶点属性状态，而VBO用于存储顶点数据。在渲染时，我们只需要绑定VAO和VBO对象，然后调用绘制函数即可。

因此，如果你只使用VAO而不使用VBO，那么你需要在每次渲染时手动传递顶点数据，这会导致CPU和GPU之间的数据传输次数增加，从而降低渲染性能。因此，使用VBO可以提高渲染性能，是一个比较好的选择。

总之，VAO和VBO各自有不同的作用，它们通常是一起使用的，以提高渲染性能。

在OpenGL中，顶点数据通常包括顶点的位置、颜色、法向量等信息。这些数据需要被传递给GPU，以便在渲染时使用。在传递数据之前，我们需要告诉OpenGL如何解释这些数据，这就是顶点属性状态的作用。

顶点属性状态是指OpenGL中用来描述顶点数据格式和内容的状态。例如，我们可以定义一个顶点属性状态，它包含了顶点的位置信息、颜色信息和法向量信息。在渲染时，我们只需要绑定这个顶点属性状态，OpenGL就会自动解释顶点数据，并将其传递给顶点着色器进行处理。

而存储顶点数据则是指将顶点数据存储在显存中，以便在渲染时快速访问。在OpenGL中，我们可以使用VBO来存储顶点数据。VBO是一个缓冲区对象，它可以将顶点数据存储在显存中，以便在渲染时快速访问。使用VBO可以减少CPU和GPU之间的数据传输次数，从而提高渲染性能。

举个例子来说，假设我们要渲染一个三角形，它的顶点数据包括位置和颜色信息。我们可以定义一个顶点属性状态，它包含了位置和颜色两个顶点属性。然后，我们可以将顶点数据存储在VBO中，并将VBO与顶点属性状态关联起来。在渲染时，我们只需要绑定VBO和顶点属性状态，OpenGL就会自动解释顶点数据，并将其传递给顶点着色器进行处理。

使用VBO可以减少CPU和GPU之间的数据传输次数，从而提高渲染性能。这是因为，当我们使用VBO时，顶点数据已经存储在显存中，CPU只需要将渲染命令发送给GPU，GPU就可以直接访问显存中的顶点数据，而不需要再从CPU中获取数据。这样可以减少CPU和GPU之间的数据传输次数，从而提高渲染性能。