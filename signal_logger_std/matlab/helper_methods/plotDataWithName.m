function plotDataWithName(data, idx, color)
    time = datetime(data(idx).systime, 'ConvertFrom', 'posixtime');
    time = time + seconds(3600);
    plot(time, data(idx).data, color{:});
end