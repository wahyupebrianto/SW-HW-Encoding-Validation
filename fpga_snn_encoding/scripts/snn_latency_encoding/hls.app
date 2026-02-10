<AutoPilot:project xmlns:AutoPilot="com.autoesl.autopilot.project" projectType="C/C++" name="snn_latency_encoding" ideType="classic" top="latency_encoding">
    <files>
        <file name="../src/encoding.h" sc="0" tb="false" cflags="" csimflags="" blackbox="false"/>
        <file name="../src/encoding.cpp" sc="0" tb="false" cflags="" csimflags="" blackbox="false"/>
        <file name="../../../data/mnist_test_images.dat" sc="0" tb="1" cflags="-Wno-unknown-pragmas" csimflags="" blackbox="false"/>
        <file name="../../../src/testbench_latency.cpp" sc="0" tb="1" cflags="-Wno-unknown-pragmas" csimflags="" blackbox="false"/>
    </files>
    <solutions>
        <solution name="solution1" status=""/>
    </solutions>
    <Simulation argv="">
        <SimFlow name="csim" setup="false" optimizeCompile="false" clean="true" ldflags="" mflags=""/>
    </Simulation>
</AutoPilot:project>

