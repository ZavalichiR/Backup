CREATE TABLE [dbo].[Excel] (
    [Id]   INT          IDENTITY (1, 1) NOT NULL,
    [Cell] VARCHAR (50) NULL,
    [Font] VARCHAR(50) NULL, 
    [Style] VARCHAR(50) NULL, 
    [Dim] NUMERIC NULL, 
    PRIMARY KEY CLUSTERED ([Id] ASC)
);

