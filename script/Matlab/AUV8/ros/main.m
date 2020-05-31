function main()
    nh = ros.Node('/proc_control_matlab');
    rate = ros.Rate(nh, 1);

    node = ProcControlNode(nh);

    while(true)
       node.spinOnce();
       waitfor(rate);
    end
end
