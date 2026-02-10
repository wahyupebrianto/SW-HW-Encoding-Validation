<AutoPilot:project xmlns:AutoPilot="com.autoesl.autopilot.project" projectType="C/C++" name="snn_rate_encoding" ideType="classic" top="rate_encoding">
    <files>
        <file name="../src/encoding.h" sc="0" tb="false" cflags="" csimflags="" blackbox="false"/>
        <file name="../src/encoding.cpp" sc="0" tb="false" cflags="" csimflags="" blackbox="false"/>
        <file name="../../../data/mnist_test_images.dat" sc="0" tb="1" cflags="-Wno-unknown-pragmas" csimflags="" blackbox="false"/>
        <file name="../../../src/testbench_rate.cpp" sc="0" tb="1" cflags="-Wno-unknown-pragmas" csimflags="" blackbox="false"/>
    </files>
    <solutions>
        <solution name="solution1" status=""/>
    </solutions>
    <Simulation argv="">
        <SimFlow name="csim" setup="false" optimizeCompile="false" clean="true" ldflags="" mflags=""/>
    </Simulation>
</AutoPilot:project>

