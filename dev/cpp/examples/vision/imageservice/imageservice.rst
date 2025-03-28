.. _cpp-tutos-images-service:

Processing images
=================

:ref:`\<\< return to C++ examples<cpp-examples>`

Principle
---------

This section explains how to implement an access to NAO's images when
the module is remote.

To retrieve the images, subscribe as usual using a proxy to ALVideoDevice, and
specify the framerate, resolution etc.

The image buffer and metadata is returned within an AnyValue. This example
shows how to parse the fields of the AnyValue.

Example: ImageService
---------------------

This example implements a module retrieving images optimally. As an example,
the image is stored in a RAW ppm image file.

The whole example is available here: :download:`imageservice.zip <../imageservice.zip>`

Camera definitions:
+++++++++++++++++++

:download:`cameradefs.h <cameradefs.h>`

.. literalinclude:: cameradefs.h
   :language: cpp

Header:
+++++++

:download:`imageservice.h <imageservice.h>`

.. literalinclude:: imageservice.h
   :language: cpp

Source:
+++++++

:download:`imageservice.cpp <imageservice.cpp>`

.. literalinclude:: imageservice.cpp
   :language: cpp

Main:
+++++

:download:`main.cpp <main.cpp>`

.. literalinclude:: main.cpp
   :language: cpp

CMakeLists.txt:
+++++++++++++++

:download:`CMakeLists.txt <CMakeLists.txt>`

.. literalinclude:: CMakeLists.txt
   :language: cmake
