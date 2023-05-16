# texture
## 纹理过滤
GL_NEAREST（也叫邻近过滤，Nearest Neighbor Filtering）是OpenGL默认的纹理过滤方式。当设置为GL_NEAREST的时候，OpenGL会选择中心点最接近纹理坐标的那个像素。
GL_LINEAR（也叫线性过滤，(Bi)linear Filtering）它会基于纹理坐标附近的纹理像素，计算出一个插值，近似出这些纹理像素之间的颜色。一个纹理像素的中心距离纹理坐标越近，那么这个纹理像素的颜色对最终的样本颜色的贡献越大。
![纹理](./img/texture_filtering.png)
多级渐远纹理(Mipmap)
距观察者的距离超过一定的阈值，OpenGL会使用不同的多级渐远纹理，即最适合物体的距离的那个
![多级渐远纹理](./img/mipmaps.png)

## 依赖下载
需要下载[stb_image.h](https://github.com/nothings/stb/blob/master/stb_image.h)