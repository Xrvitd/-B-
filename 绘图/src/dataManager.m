Pxx = [];
Pyy = [];
Txx = [];
Tyy = [];
for i = 1:32
    if(i~= 4&&i~=20)
        Px = [0];
        Py = [0];
        Tx = [0];
        Ty = [0];
        for j = 1:4
        px = 10.^(raw_data.LogMag(:,:,i,j)./20).*cos(deg2rad(Phase(:,:,i,j)));
        Px = [Px, px(39,20)];
        py = 10.^(raw_data.LogMag(:,:,i,j)./20).*sin(deg2rad(Phase(:,:,i,j)));
        Py = [Py, py(39,20)];
        tx = 10.^(raw_data.LogMag(:,:,i,j)./20).*cos(deg2rad(Phase(:,:,i,j)));
        Tx = [Tx, tx(39,21)];
        ty = 10.^(raw_data.LogMag(:,:,i,j)./20).*sin(deg2rad(Phase(:,:,i,j)));
        Ty = [Ty, ty(39,21)];
        end
    else
        Px = [0,0,0,0,0];
        Py = [0,0,0,0,0];
        Tx = [0,0,0,0,0];
        Ty = [0,0,0,0,0];
    end
    Pxx = [Pxx,Px'];
    Pyy = [Pyy,Py'];
    Txx = [Txx,Tx'];
    Tyy = [Tyy,Ty'];
end
dlmwrite("Pxxiu.csv",Pxx','precision',32);
dlmwrite("Pyxiu.csv",Pyy','precision',32);
dlmwrite("Txxiu.csv",Txx','precision',32);
dlmwrite("Tyxiu.csv",Tyy','precision',32);